import mysql.connector
import datetime

def schema(host,user,password):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')

    #초기화
    cursor.execute('DROP DATABASE IF EXISTS bank;')
    cursor.execute('CREATE DATABASE IF NOT EXISTS bank;')

    cursor.close()

def table(host, user, password):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')

    cursor.execute('USE bank;')

    #계좌
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS acc(
    acc_number VARCHAR(8) NOT NULL ,
    acc_money VARCHAR(32) DEFAULT '0', 
    acc_date VARCHAR(16) NOT NULL, 
    acc_user_number VARCHAR(8) NOT NULL,
    PRIMARY KEY (acc_number) );
    ''')

    #거래
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS trans(
    trans_number VARCHAR(8) NOT NULL ,
    trans_type VARCHAR(16) NOT NULL,
    trans_date VARCHAR(16) NOT NULL, 
    trans_money VARCHAR(11) NOT NULL, 
    trans_acc_number VARCHAR(8) NOT NULL,
    PRIMARY KEY (trans_number) );
    ''')

    #관리자
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS admin(
    admin_number VARCHAR(8) NOT NULL ,
    admin_adress VARCHAR(255) NOT NULL,
    admin_name VARCHAR(16) NOT NULL,
    admin_phone VARCHAR(16) NOT NULL,
    admin_ssn VARCHAR(13) NOT NULL, 
    PRIMARY KEY (admin_number) );
    ''')
    cursor.execute('''
    INSERT INTO admin VALUES ('1','의왕시','신상윤','01047405160','990428');
    ''')

    #사용자
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS user(
    user_number VARCHAR(8) NOT NULL ,
    user_name VARCHAR(32) NOT NULL,
    user_adress VARCHAR(255) NOT NULL,
    user_phone VARCHAR(16) NOT NULL,
    user_ssn VARCHAR(16) NOT NULL,
    user_accnum VARCHAR(3) NOT NULL,
    PRIMARY KEY (user_number) );
    ''')

    #관리
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS manage(
    manage_admin_number VARCHAR(8) NOT NULL ,
    manage_user_number VARCHAR(8) NOT NULL ,
    PRIMARY KEY (manage_admin_number, manage_user_number) );
    ''')

    #meta-data
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS md(
    md_acc CHAR(8) DEFAULT '1',
    md_use CHAR(8) DEFAULT '1',
    md_admin CHAR(8) DEFAULT '2',
    md_trans CHAR(8) DEFAULT '1',
    PRIMARY KEY (md_acc) );
    ''')
    cursor.execute('''
    INSERT INTO md VALUES ();
    ''')
    cnx.commit()
    cursor.close()

def new_user(host, user, password):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')
    s = input("\n이름,주소,연락처,주민번호를 입력해주세요: ")

    cursor.execute('''
    SELECT md_use
    FROM md;
    ''')
    user_number = 0
    for ddd in cursor:
        user_number = int(ddd[0])

    # DB에는 다음번호로 업데이트됨 아직 사용안된 번호임!!
    cursor.execute('''UPDATE md SET md_use = ''' + str(user_number+1) + ''';''')
    s = str(user_number) + " " + s + " 1" #처음 보유계좌수는 1, 필수로 하나 만들어야됨!
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO user' + ' VALUES {};'.format(s)
    cursor.execute(sql)

    cursor.execute('''
    SELECT md_acc
    FROM md;
    ''')
    acc_number = 0
    for ddd in cursor:
        acc_number = int(ddd[0])
        
    cursor.execute('''UPDATE md SET md_acc = ''' + str(acc_number+1) + ''';''')
    dt_now = datetime.datetime.now()
    s = str(acc_number) + " 0 " + str(dt_now.date()) + " " + str(user_number)
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO acc' + ' VALUES {};'.format(s)
    cursor.execute(sql)
    
    #관리로 관리자랑 연결 해야됨
    cursor.execute('''
    SELECT admin_number
    FROM admin;
    ''')

    row = cursor.fetchall()
    for ddd in row:
        admin_number = ddd[0]
        cursor.execute('''INSERT INTO manage VALUES ('''+ admin_number + ''',''' + str(user_number) + ''');''')
    
    cnx.commit()
    cursor.close()
    print("\n회원가입을 축하합니다!! 당신의 회원번호는 " + str(user_number) + "\n계좌번호는 "+ str(acc_number) + "입니다 잊지 않도록 주의하세요!!")
    
    

def whoareyou(host, user, password,user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')
    cursor.execute('''
    SELECT user_name
    FROM user
    WHERE user_number="'''+user_number+'''";
    ''')
    user_name = ""
    for ddd in cursor:
        user_name = str(ddd[0])
    cursor.close()
    return user_name

def check_user_accnum(host, user, password,user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')
    cursor.execute('''
    SELECT user_accnum
    FROM user
    WHERE user_number="'''+user_number+'''";
    ''')
    user_accnum = 0
    for ddd in cursor:
        user_accnum = int(ddd[0])
    cursor.close()
    return user_accnum


def new_acc(host, user, password,user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT md_acc
    FROM md;
    ''')
    acc_number = 0
    for ddd in cursor:
        acc_number = int(ddd[0])
        
    cursor.execute('''UPDATE md SET md_acc = ''' + str(acc_number+1) + ''';''')

    dt_now = datetime.datetime.now()
    s = str(acc_number) + " 0 " + str(dt_now.date()) + " " + user_number
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO acc' + ' VALUES {};'.format(s)
    cursor.execute(sql)


    #사용자 보유 계좌 수 늘려야됨
    cursor.execute('''
    SELECT user_accnum
    FROM user
    WHERE user_number = ''' + user_number + ''';''')
    user_accnum = 0
    for ddd in cursor:
        user_accnum = int(ddd[0])    
    cursor.execute('''UPDATE user SET user_accnum = ''' + str(user_accnum+1) + '''
    WHERE user_number = ''' + user_number + ''';''')
    cnx.commit()
    cursor.close()
    print("\n성공적으로 계좌가 만들어졌습니다! 계좌번호는 " + str(acc_number) + "입니다")

def my_acc(host, user, password, user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT acc_number
    FROM acc, user
    WHERE user_number = ''' + user_number + ''' and acc_user_number = user_number;
    ''')

    user_acc = ""
    for ddd in cursor:
        user_acc += str(ddd[0])+" "
    cursor.close()
    if user_acc == "":
        print("\n 보유중인 계좌가 없습니다!")
    else:
        print("\n보유중인 계좌는 " + user_acc + "입니다.")


def check_acc_money(host, user, password, user_number, acc_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT acc_money
    FROM acc, user
    WHERE user_number = ''' + user_number + ''' and acc_user_number = user_number and acc_number = '''+ acc_number +''';''')

    acc_money = ""
    for ddd in cursor:
        acc_money = str(ddd[0])
    cursor.close()
    return acc_money

def in_acc_money(host, user, password, user_number, acc_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT acc_money
    FROM acc, user
    WHERE user_number = ''' + user_number + ''' and acc_user_number = user_number and acc_number = '''+ acc_number +''';''')

    acc_money = ""
    for ddd in cursor:
        acc_money = str(ddd[0])

    if acc_money == "":
        print("\n계좌번호가 잘못되었습니다!!")
        cursor.close()
        return
    money = input("\n입금하고싶은 금액을 입력해주세요. ")

    #total_money로 업데이트 해야됨
    total_money = int(acc_money) + int(money)

    cursor.execute('''UPDATE acc SET acc_money = ''' + str(total_money) + ''' WHERE acc_number = ''' + acc_number + ''';''')

    #거래기록 추가
    cursor.execute('''
    SELECT md_trans
    FROM md;
    ''')
    trans_number = 0
    for ddd in cursor:
        trans_number = int(ddd[0])
        
    cursor.execute('''UPDATE md SET md_trans = ''' + str(trans_number+1) + ''';''')
    dt_now = datetime.datetime.now()
    s = str(trans_number) + " 입금 " + str(dt_now.date()) + " " + money + " " + acc_number
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO trans' + ' VALUES {};'.format(s)
    cursor.execute(sql)
    cnx.commit()
    cursor.close()
    print("\n입금이 완료되었습니다")


def out_acc_money(host, user, password, user_number, acc_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT acc_money
    FROM acc, user
    WHERE user_number = ''' + user_number + ''' and acc_user_number = user_number and acc_number = '''+ acc_number +''';''')

    acc_money = ""
    for ddd in cursor:
        acc_money = str(ddd[0])

    if acc_money == "":
        print("\n계좌번호가 잘못되었습니다!!")
        cursor.close()
        return
    money = input("\n출금하고싶은 금액을 입력해주세요. ")

    #total_money로 업데이트 해야됨
    total_money = int(acc_money) - int(money)

    if total_money < 0:
        print("\n잔액이 부족합니다!!")
        cursor.close()
        return

    cursor.execute('''UPDATE acc SET acc_money = ''' + str(total_money) + ''' WHERE acc_number = ''' + acc_number + ''';''')

    #거래기록 추가
    cursor.execute('''
    SELECT md_trans
    FROM md;
    ''')
    trans_number = 0
    for ddd in cursor:
        trans_number = int(ddd[0])
        
    cursor.execute('''UPDATE md SET md_trans = ''' + str(trans_number+1) + ''';''')
    dt_now = datetime.datetime.now()
    s = str(trans_number) + " 출금 " + str(dt_now.date()) + " " + money + " " + acc_number
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO trans' + ' VALUES {};'.format(s)
    cursor.execute(sql)
    cnx.commit()
    cursor.close()
    print("\n출금이 완료되었습니다")


def del_acc_number(host, user, password, user_number, acc_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT acc_money
    FROM acc, user
    WHERE user_number = ''' + user_number + ''' and acc_user_number = user_number and acc_number = '''+ acc_number +''';''')

    acc_money = ""
    for ddd in cursor:
        acc_money = str(ddd[0])

    if acc_money == "":
        print("\n계좌번호가 잘못되었습니다!!")
        cursor.close()
        return

    #계좌 삭제하면서 동시에 자동으로 잔액 출금 & 거래기록 추가 이때 기록은 '계좌 해지로인한 출금'
    if int(acc_money) > 0:
        cursor.execute('''
        SELECT md_trans
        FROM md;
        ''')
        trans_number = 0
        for ddd in cursor:
            trans_number = int(ddd[0])
            
        cursor.execute('''UPDATE md SET md_trans = ''' + str(trans_number+1) + ''';''')
        dt_now = datetime.datetime.now()
        s = str(trans_number) + " 계좌해지로인한출금 " + str(dt_now.date()) + " " + acc_money + " " + acc_number
        s = s.strip().split(' ')
        s = tuple(s)
        sql = 'INSERT INTO trans' + ' VALUES {};'.format(s)
        cursor.execute(sql)

    #이후 계좌 관련 table 모두 삭제
    cursor.execute('''
    DELETE FROM acc
    WHERE acc_number = '''+ acc_number +''';''')

    #보유 계좌수도 줄임
    cursor.execute('''
    SELECT user_accnum
    FROM user
    WHERE user_number = '''+ user_number +''';''')
    user_accnum = 0
    for ddd in cursor:
        user_accnum = int(ddd[0])
    cursor.execute('''UPDATE user SET user_accnum = ''' + str(user_accnum - 1) + ''' WHERE user_number = '''+ user_number +''';''')
    cnx.commit()
    cursor.close()
    print("\n계좌 해지 완료")


def del_user_number(host, user, password, user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT user_accnum
    FROM user
    WHERE user_number = ''' + user_number + ''';''')

    user_accnum = 0
    for ddd in cursor:
        user_accnum = int(ddd[0])

    if user_accnum != 0:
        print("\n보유중인 계좌가 남아있습니다! 계좌 해지부터 해주세요!")
        cursor.close()
        return

    cursor.execute('''
    DELETE FROM user
    WHERE user_number = '''+ user_number +''';''')
    cnx.commit()
    cursor.close()
    print("\n회원탈퇴가 완료되었습니다. 그동안 이용해주셔서 감사합니다")


def user_my_trans(host, user, password, user_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT trans_acc_number, trans_date, trans_type, trans_money
    FROM user,acc,trans
    WHERE user_number = ''' + user_number + ''' and acc_user_number = ''' + user_number + ''' and acc_number = trans_acc_number;''')

    print("\n계좌번호 날짜 입금/출금 금액\n")
    cnt = 0
    for ddd in cursor:
        s = ""
        for eee in ddd:
            s += str(eee) + " "
        print(s)
        cnt = cnt+1
        if cnt > 20:
            break
    cursor.close()

def new_admin(host, user, password):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT md_admin
    FROM md;
    ''')
    admin_number = 0
    for ddd in cursor:
        admin_number = int(ddd[0])
            
    cursor.execute('''UPDATE md SET md_admin = ''' + str(admin_number+1) + ''';''')
    
    s = input("\n주소,이름,연락처,주민번호를 입력해주세요: ")
    s = str(admin_number) + " " + s
    s = s.strip().split(' ')
    s = tuple(s)
    sql = 'INSERT INTO admin' + ' VALUES {};'.format(s)
    cursor.execute(sql)
    cnx.commit()
    cursor.close()
    print("\n새 관리자님 환영합니다!")

def whoareyouadmin(host, user, password, admin_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT admin_name
    FROM admin
    WHERE admin_number = ''' + admin_number + ''';''')

    admin_name = ""
    for ddd in cursor:
        admin_name = str(ddd[0])
    cursor.close()
    return admin_name

def admin_user(host, user, password, admin_number):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT user_name, acc_number
    FROM manage, user, acc
    WHERE manage_admin_number = ''' + admin_number + ''' and manage_user_number = user_number and user_number = acc_user_number;''')

    for ddd in cursor:
        s = ""
        for eee in ddd:
            s += str(eee) + " "
        print(s)
    cursor.close()

def trans_print(host, user, password):
    cnx = mysql.connector.connect(host=host, user=user, password=password)
    cursor = cnx.cursor()
    cursor.execute('SET GLOBAL innodb_buffer_pool_size=2*1024*1024*1024;')
    cursor.execute('USE bank;')

    cursor.execute('''
    SELECT trans_acc_number, trans_date, trans_type, trans_money
    FROM trans;''')

    print("\n계좌번호 날짜 입금/출금 금액\n")
    cnt = 0
    for ddd in cursor:
        s = ""
        for eee in ddd:
            s += str(eee) + " "
        print(s)
        cnt += 1
        if cnt > 20:
            break
    cursor.close()
    

host = 'localhost'
user = 'root'
password = 'kas123123'

schema(host, user, password)
table(host, user, password)

while True:
    number = input("\n당신은?\n\n1.관리자\n2.사용자\n3.프로그램을 종료한다.")
    
    if number == "1":
        pw = input("\n비밀번호를 입력해주세요 : ")
        if pw == 'kas123123':
            #관리자 페이지
            who = input("\n안녕하세요 관리자님 관리자 번호를 입력해주세요. 신규 관리자 등록을 원하시면 -1을 입력해주세요.")

            if who == "-1":
                new_admin(host, user, password)
            else:
                admin_name = whoareyouadmin(host, user, password, who)
                if admin_name == "":
                    print("\n등록되지 않은 관리자 입니다!!")

                else:
                    print("\n안녕하세요 " + admin_name + " 관리자님")
                    us = input("\n어떤 업무로 오셨나요?\n\n1.담당 회원/계좌 확인\n2.최근 거래기록 확인")
                if us == "1":
                    admin_user(host, user, password, who)
                    
                elif us == "2":
                    trans_print(host, user, password)
                    
                else:
                    print("\n입력이 잘못됬습니다. 처음으로 돌아갑니다")
                    continue

            
            
        else:
            print("\n비밀번호가 틀렸습니다. 처음으로 돌아갑니다.")
            continue

    elif number == "2":
        #사용자 화면
        who = input("\n회원번호를 입력해주세요. 신규등록을 원하시면 -1을 입력해주세요.")
        if who == "-1":
            new_user(host, user, password)
        else:
            name = whoareyou(host, user, password, who)
            if name == "":
                print("\n등록되지 않은 회원 입니다!!")
                continue
            else:
                print("\n안녕하세요 " + name + "님")
                us = input("\n어떤 업무로 오셨나요?\n\n1.계좌생성\n2.잔액확인\n3.입금\n4.출금\n5.계좌 해지\n6.회원탈퇴\n7.최근 입출금 내역")

                if us == "1":
                    check_accnum = check_user_accnum(host, user, password, who)
                    if check_accnum == 3:
                        print("\n이미 등록된 계좌가 3개입니다!!!")
                        continue
                    else:
                        new_acc(host, user, password, who)
                        
                elif us == "2":
                    #보유계좌 확인
                    my_acc(host,user,password, who)

                    acc = input("\n잔액확인을 하고싶은 계좌번호를 입력해주세요. ")
                    
                    #보유계좌 잔액 리턴
                    check_money = check_acc_money(host, user, password, who, acc)
                    if check_money == "":
                        print("\n계좌번호가 잘못되었습니다!!")
                        continue
                    else:
                        print("\n보유하고 계신 잔액은 " + check_money + "원 입니다.")

                elif us == "3":
                    #보유계좌 확인
                    my_acc(host,user,password, who)
                    
                    acc = input("\n입금을 하고싶은 계좌번호를 입력해주세요. ")

                    in_acc = in_acc_money(host, user, password, who, acc)

                elif us == "4":
                    #보유계좌 확인
                    my_acc(host,user,password, who)
                    
                    acc = input("\n출금을 하고싶은 계좌번호를 입력해주세요. ")

                    out_acc = out_acc_money(host, user, password, who, acc)

                elif us == "5":
                    #보유계좌 확인
                    my_acc(host,user,password, who)
                    
                    acc = input("\n해지 하고싶은 계좌번호를 입력해주세요. ")

                    del_acc = del_acc_number(host, user, password, who, acc)

                elif us == "6":
                    #회원탈퇴는 보유계좌가 0일때만 가능 즉, 해지 후 이용가능
                    del_user = del_user_number(host, user, password, who)

                elif us == "7":
                    my_trans = user_my_trans(host, user, password, who)

                else:
                    print("\n입력이 잘못되었습니다. 처음으로 돌아갑니다.")
                    continue
                
        
    elif number == "3":
        break

    else:
        print("\n입력이 잘못되었습니다. 처음으로 돌아갑니다.")
        continue
    
