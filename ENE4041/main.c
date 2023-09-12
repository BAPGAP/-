#include "msp.h"
#include "Clock.h"
#include <stdio.h>
#define RED 1
#define GREEN 2
#define BLUE 4

void led_init() {
    P2->SEL0 &= ~0x07;
    P2->SEL1 &= ~0x07;
    P2->DIR |= 0x07;
    P2->OUT &= ~0x07;
}
void switch_init() {
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;
    P1->DIR &= ~0x12;
    P1->REN |= 0x12;
    P1->OUT |= 0x12;
}
void turn_on_led(int color) {
    P2->OUT &= ~0x07;
    P2->OUT |= color;
}
void turn_off_led() {
    P2->OUT &= ~0x07;
}
void systick_init() {
    SysTick->LOAD = 0x00FFFFFF;
    SysTick->CTRL = 0x00000005;
}
void systick_wait1ms() {
    SysTick->LOAD = 48000;
    SysTick->VAL = 0;
    while((SysTick->CTRL & 0x00010000) == 0) {};
}
void systick_wait1s() {
    int count = 1000, i;
    for (i = 0; i < count; i++) {
        systick_wait1ms();
    }
}
void IR_init() {
    P5->SEL0 &= ~0x08;
    P5->SEL1 &= ~0x08;
    P5->DIR |= 0x08;
    P5->OUT &= ~0x08;

    P9->SEL0 &= ~0x04;
    P9->SEL1 &= ~0x04;
    P9->DIR |= 0x04;
    P9->OUT &= ~0x04;

    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR &= ~0xFF;
}
void motor_init() {
    P3->SEL0 &= ~0xC0;
    P3->SEL1 &= ~0xC0;
    P3->DIR |= 0xC0;
    P3->OUT &= ~0xC0;

    P5->SEL0 &= ~0x30;
    P5->SEL1 &= ~0x30;
    P5->DIR |= 0x30;
    P5->OUT &= ~0x30;

    P2->SEL0 &= ~0xC0;
    P2->SEL1 &= ~0xC0;
    P2->DIR |= 0xC0;
    P2->OUT &= ~0xC0;

    pwm_init34(7500, 0, 0);
}
void motor(int speed) {
    P5->OUT &= ~0x30;
    P2->OUT |= 0xC0;
    P3->OUT |= 0xC0;
    Clock_Delay1us(speed);

    P2->OUT &= ~0xC0;
    Clock_Delay1us(10000-speed);
}
void pwm_init34(uint16_t period, uint16_t duty3, uint16_t duty4) {
    TIMER_A0->CCR[0] = period;
    TIMER_A0->EX0 = 0x0000;
    TIMER_A0->CCTL[3] = 0x0040;
    TIMER_A0->CCR[3] = duty3;
    TIMER_A0->CCTL[4] = 0x0040;
    TIMER_A0->CCR[4] = duty4;
    TIMER_A0->CTL = 0x02F0;
    P2->DIR |= 0xC0;
    P2->SEL0 |= 0xC0;
    P2->SEL1 &= ~0xC0;
}
void move(uint16_t leftDuty, uint16_t rightDuty) {
    P3->OUT |= 0xC0;
    TIMER_A0->CCR[3] = leftDuty;
    TIMER_A0->CCR[4] = rightDuty;
}
void left_forward() {
    P5->OUT &= ~0x10;
}
void right_forward() {
    P5->OUT &= ~0x20;
}
void left_backward() {
    P5->OUT |= 0x10;
}
void right_backward() {
    P5->OUT |= 0x20;
}

void timer_A3_capture_init() {
    P10->SEL0 |= 0x30;
    P10->SEL1 &= ~0x30;
    P10->DIR &= ~0x30;

    TIMER_A3->CTL &= ~0x0030;
    TIMER_A3->CTL = 0x0200;

    TIMER_A3->CCTL[0] = 0x4910;
    TIMER_A3->CCTL[1] = 0x4910;
    TIMER_A3->EX0 &= ~0x0007;

    NVIC->IP[3] = (NVIC->IP[3]&0x0000FFFF) | 0x404000000;
    NVIC->ISER[0] = 0x0000C000;
    TIMER_A3->CTL |= 0x0024;
}


uint16_t first_left;
uint16_t first_right;

uint16_t period_left;
uint16_t period_right;

/*
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    period_right = TIMER_A3->CCR[0] - first_right;
    first_right = TIMER_A3->CCR[0];
}
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    period_left = TIMER_A3->CCR[1] - first_left;
    first_left = TIMER_A3->CCR[1];
}*/
uint32_t get_left_rpm() {
    return 2000000 / period_left;
}

uint32_t right_count;
void TA3_0_IRQHandler(void) {
    TIMER_A3->CCTL[0] &= ~0x0001;
    right_count++;
}
uint32_t left_count;
void TA3_N_IRQHandler(void) {
    TIMER_A3->CCTL[1] &= ~0x0001;
    left_count++;
}

int speed = 2000;
int term_speed = 1000;
int l_speed = 1500;
int t_speed = 2000;
int black = 1000;
int line_l = 0x30; // 00110000
int line_r = 0x0C; // 00001100
int turn_l = 0xC0; // 11000000
int turn_r = 0x03; // 00000011

void line_trace() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & line_l;
        s2 = P7->IN & line_r;
        s3 = P7->IN & turn_l;
        s4 = P7->IN & turn_r;

        if (!s1) {
            left_forward();
            right_forward();
            move(1500, 1500);
        }
        else if (!s2) {
            left_forward();
            right_forward();
            move(1500, 1500);
        }
        else {
            left_forward();
            right_forward();
            move(1500, 1500);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}
void fL() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & line_l;
        s2 = P7->IN & line_r;
        s3 = P7->IN & turn_l;
        s4 = P7->IN & turn_r;

        if (s3) {
            left_forward();
            right_forward();
            move(speed, speed);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (!s1) {
            left_forward();
            right_forward();
            move(l_speed, speed);
        }
        else if (!s2) {
            left_forward();
            right_forward();
            move(speed, l_speed);
        }
        else {
            left_forward();
            right_forward();
            move(speed, speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}
void fL_2() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & line_l;
        s2 = P7->IN & line_r;
        s3 = P7->IN & turn_l;
        s4 = P7->IN & turn_r;

        if (s3) {
            left_forward();
            right_forward();
            move(speed, speed);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }
        else if (!s1 && !s2){
            left_forward();
            right_forward();
            move(speed, speed);
        }
        else if (!s1) {
            left_forward();
            right_forward();
            move(l_speed, speed);
        }
        else if (!s2) {
            left_forward();
            right_forward();
            move(speed, l_speed);
        }
        else {
            left_forward();
            right_forward();
            move(speed, speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}
void fR() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & line_l;
        s2 = P7->IN & line_r;
        s3 = P7->IN & turn_l;
        s4 = P7->IN & turn_r;

        if (s4) {
            left_forward();
            right_forward();
            move(speed, speed);
            P5->OUT &= ~0x08;
            P9->OUT &= ~0x04;
            break;
        }

        if (!s1) {
            left_forward();
            right_forward();
            move(l_speed, speed);
        }
        else if (!s2) {
            left_forward();
            right_forward();
            move(speed, l_speed);
        }
        else {
            left_forward();
            right_forward();
            move(speed, speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}
void term(int n) {
    left_forward();
    right_forward();
    move(speed, speed);
    left_count = 0;
    while(1) {
        if (left_count > n) {
            move(0, 0);
            break;
        }
    }
}
void term_2(int n){
    left_forward();
    right_forward();
    move(term_speed, term_speed);
    left_count = 0;
    while(1){
        if(left_count > n){
            move(0,0);
            break;
        }
    }
}
void tL(int d) {
    term_2(50);
    left_count = 0;
    left_backward();
    right_forward();
    move(t_speed, t_speed);
    while(1) {
        if (left_count > 2 * d) {
            move(0, 0);
            break;
        }
    }
    term(60);
}
void tR(int d) {
    term_2(50);
    left_forward();
    right_backward();
    move(t_speed, t_speed);
    right_count = 0;
    while(1) {
        if (right_count > 2 * d) {
            move(0, 0);
            break;
        }
    }
    term(60);
}
void tL_2(int d) {
    term(30);
    left_count = 0;
    left_backward();
    right_forward();
    move(t_speed, t_speed);
    while(1) {
        if (left_count > 2 * d) {
            move(0, 0);
            break;
        }
    }
    term(30);
}
void tR_2(int d) {
    term(30);
    left_forward();
    right_backward();
    move(t_speed, t_speed);
    right_count = 0;
    while(1) {
        if (right_count > 2 * d) {
            move(0, 0);
            break;
        }
    }
    term(30);
}
void sL() {
    fL();
    term(90);
}
void sR() {
    fR();
    term(90);
}
void mid() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & 0x10; // 00010000
        s2 = P7->IN & 0x08; // 00001000
        s3 = P7->IN & 0x20; // 00100000
        s4 = P7->IN & 0x04; // 00000100

        if (s1 && s2) {
            move(0, 0);
            break;
        }
        else {
            left_forward();
            right_backward();
            move(speed, speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}
int lab = 1;
void end() {
    while (1) {
        int s1, s2, s3, s4;
        P5->OUT |= 0x08;
        P9->OUT |= 0x04;
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);
        P7->DIR = 0x00;
        Clock_Delay1us(black);

        s1 = P7->IN & 0x10; // 00010000
        s2 = P7->IN & 0x08; // 00001000
        s3 = P7->IN & 0x20; // 00100000
        s4 = P7->IN & 0x04; // 00000100

        if (s3 && s4) {
            if (lab == 2) {
                move(0, 0);
                break;
            }
            else {
                lab++;
                term(100);
                break;
            }
        }

        if (!s1) {
            left_forward();
            right_forward();
            move(l_speed, speed);
        }
        else if (!s2) {
            left_forward();
            right_forward();
            move(speed, l_speed);
        }
        else {
            left_forward();
            right_forward();
            move(speed, speed);
        }

        P5->OUT &= ~0x08;
        P9->OUT &= ~0x04;
        Clock_Delay1ms(1);
    }
}

void main(void) {

    Clock_Init48MHz();
    led_init();
    switch_init();
    systick_init();
    IR_init();
    motor_init();
    timer_A3_capture_init();

    /****************************************************\
     *
     * speed : 기본 속도
     * l_speed : line tracing 하기 위해 회전해야하는 속도
     * t_speed : turn 하기 위해 회전해야하는 속도
     * line_l & line_r : line tracing 하기 위한 IR센서 위치
     * turn_l & turn_r : turn 하기 위한 IR센서 위치
     *
     * fL() & fR() : 왼쪽/오른쪽 길이 나올 때 까지 line trace
     * tL(d) & tR(d) : 각도 d만큼 왼쪽/오른쪽으로 회전 후에 약간 이동
     * sR() : fR 실행 후 약간 이동 (스킵하기 위함)
     *
    \****************************************************/

    //*

    speed = 2820;
    term_speed = 1000;
    l_speed = 500;
    t_speed = 2820;
    black = 1000;

    line_l = 0x30; // 00110000
    line_r = 0x0C; // 00001100
    turn_l = 0x80; // 10000000
    turn_r = 0x01; // 00000001

    int _90 = 75;
    int d8 = 90;
    int d9 = 65;
    int d11 = 100;
    int d14 = 100;
    int d15 = 120;
    int d17= 50;
    int d19 = 15;
    int d27 = 15;
    int d30 = 100;
    int d38 = 90;
    int d39 = 90;

    int i;
    for (i = 0; i < 2; i++) {
        //#1
        fR();
        tR(_90);
        //#2
        fR();
        tR(_90);
        //#3,4,5,6
        fR();
        term(40);
        fR();
        tR(_90);
        fL();
        tL(_90);
        fR();
        tR(_90);
        fL();
        tL(_90);
        //#7
        fL();
        tL(_90);

        //#8
        fL();
        tL(d8);
        //#9
        fR();
        tR(d9);
        //#10
        fR();
        tR(_90);
        //#11
        fL();
        tL(d11);
        //#12
        fL();
        tL(80);
        term(30);
        //#13
        while(1){
            //센서 기본 코드
            P5 -> OUT |= 0x08;
            P9 -> OUT |= 0x04;
            P7 -> DIR = 0xFF;
            P7 -> OUT = 0xFF;
            Clock_Delay1us(10);
            P7 -> DIR = 0x00;
            Clock_Delay1us(black);
            //센서 기본 코드
            int five = P7 -> IN & 0x0C; //00001000
            int four = P7 -> IN & 0x30; //00010000
            int L_find = P7 -> IN & 0x40; //01000000 좌회전
            //목표 : four, five는 항상 11이어야함
            if(L_find){
                left_forward();
                right_forward();
                move(0,0);
                break;
            }
            else if(!five){
                left_backward();
                right_forward();
                move(2500,2500);
            }
            else if(!four){
                left_forward();
                right_backward();
                move(2500,2500);
            }
            else{
                left_forward();
                right_forward();
                move(2500,2500);
            }
            //센서 기본 코드
            P5 -> OUT &= ~0x08;
            P9 -> OUT &= ~0x04;
            Clock_Delay1ms(10);
            //센서 기본 코드
        }
        //#14
        fL();
        tL(85);
        //#15
        fL();
        tL(85);
        //#16
        fR();
        tR(70);
        //#17
        fR();
        tR(45);
        //#18
        fR();
        tR(_90);
        //#19
        fR();
        tR_2(20);
        //#20
        fL();
        tL_2(_90);
        //#21
        fR();
        tR_2(_90);
        //#22
        fL();
        tL_2(_90);
        //#23
        fR();
        tR_2(_90);
        //#24
        fL();
        tL_2(_90);
        //#25
        fR();
        tR_2(_90);
        //#26
        fL();
        tL_2(_90);
        //#27
        fR();
        mid();
        //#28
        fL_2();
        tL(_90);
        //#29
        fR();
        tR(_90);
        //#30
        fR();
        tR(115);
        term(90);
        //#31
        fL();
        tL(_90);
        //#32
        fR();
        tR(_90);
        //#33
        fR();
        tR(_90);
        //#34
        fL();
        tL(_90);
        //#35
        fL();
        tL(_90);
        //#36
        fL();
        tL(_90);
        //#37
        fR();
        tR(_90);
        //#38
        fR();
        tR(d38);
        //#39
        fL();
        tL(d39);
        //#40
        fR();
        tR(_90);
        //#41
        fR();
        tR(_90);
        //#42
        fL();
        tL(_90);
        //#43
        fR();
        tR(_90);
        //#44
        end();
    }
}
