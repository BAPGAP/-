import java.io.*;

public class bptree {
	static int max_degree;
	static int min_key; //각 node는 최소 min_key만큼 key를 가져야함
	static node root;
	static node[] adress;
	static String[] treeinfo;
	static String[] outputstring; //내보낼 트리 정보
	static int cnt;
	static class data{
		public int gap; // 구현하는 자료구조의 자료에는 gap이 들어있음
		public data(int v){
			gap = v;
		}
	}
	static class node{
		public int m; // # key
		public boolean isleaf; //leaf or nonleaf
		public int[] key;
		public data[] value;
		public node[] left_child_node;
		public node rightnode; //leaf면 오른쪽 형제가 저장되고, leaf가 아니면 가장 오른쪽 자식이 저장된다.
		public int num;
		
		public node(int k,int v,boolean b){
			m = 1;
			isleaf = b;
			key = new int[max_degree+1];
			key[0] = k;
			if(b) {
				value = new data[max_degree+1];
				for(int i=0; i<max_degree+1; i++) {
					value[i] = new data(v);
				}
			}
			else {
				left_child_node = new node[max_degree+1];
				for(int i=0; i<max_degree+1; i++) {
					left_child_node[i] = (node) null;
				}
			}
			rightnode = (node) null;
		}
		public node(String s){
			String[] nodeinfo = s.split(" ");
			m = Integer.parseInt(nodeinfo[0]);
        	isleaf = Boolean.parseBoolean(nodeinfo[1]);
        	key = new int[max_degree+1];
        	for(int i=2; i<=m+1; i++) {
        		key[i-2] = Integer.parseInt(nodeinfo[i]);
        	}
        	if(isleaf) {
				value = new data[max_degree+1];
				for(int i=m+2; i<=2*m+1; i++) {
					value[i-m-2] = new data(Integer.parseInt(nodeinfo[i]));
				}
				for(int i=m; i<=max_degree; i++) {
					value[i] = new data(0);
				}
			}
		}
	} 
	
	public static void connect(String s,int x) {
		node tmp = adress[x];
		String[] nodeinfo = s.split(" ");
    	int next = Integer.parseInt(nodeinfo[2*tmp.m+2]);
    	if(!tmp.isleaf){
    		tmp.left_child_node = new node[max_degree+1];
    		for(int i=tmp.m+2; i<=2*tmp.m+1; i++) {
    			int baby = Integer.parseInt(nodeinfo[i]);
    			tmp.left_child_node[i-tmp.m-2] = adress[baby];
    		}
    		for(int i=tmp.m; i<=max_degree; i++) {
    			tmp.left_child_node[i] = (node) null;
    		}
    	}
    	if(next == 0) tmp.rightnode = (node) null;
		else tmp.rightnode = adress[next];
	}
	
	public static void split(node parent,node child,int parentpos){ //if child is full
	    int pos = max_degree/2;
	    
	    node new_node = new node(0,0,child.isleaf);
	    
	    child.m = pos;

	    if(child.isleaf){
	        for(int i=pos; i<max_degree; i++){
	            new_node.key[i-pos] = child.key[i];
	            new_node.value[i-pos].gap = child.value[i].gap;
	        }
	        new_node.m = max_degree - pos;
	        new_node.rightnode = child.rightnode;
	        child.rightnode = new_node;
	    }
	    else{
	        for(int i=pos+1; i<max_degree; i++){
	            new_node.key[i-pos-1] = child.key[i];
	            new_node.left_child_node[i-pos-1] = child.left_child_node[i];
	        }
	        new_node.m = max_degree - pos - 1;
	        new_node.rightnode = child.rightnode;
	        child.rightnode = child.left_child_node[pos];
	    }

	    int k = child.key[pos];

	    if(parent == (node) null){ //new root
	        //새로 생기는 루트는 무조건 non leaf
	        node new_root = new node(k,0,false);
	        new_root.left_child_node[0] = child;
	        new_root.rightnode = new_node;
	        root = new_root;
	        return;
	    }

	    //child가 leaf든 아니든 부모는 무조건 nonleaf
	    
	    for(int i=parent.m; i>parentpos; i--) {
	    	parent.key[i] = parent.key[i-1];
	    	parent.left_child_node[i] = parent.left_child_node[i-1];
	    }
	    parent.left_child_node[parentpos] = child;
	    if(parentpos == parent.m) parent.rightnode = new_node;
	    else parent.left_child_node[parentpos+1] = new_node;
	    parent.key[parentpos] = k;
	    parent.m += 1;
	    return;
	}
	
	public static node insertion(node T,int k,int v){
	    if(T.isleaf){
	        for(int i=T.m; i>0; i--){
	            if(k > T.key[i-1]){
	                T.key[i] = k;
	                T.value[i].gap = v;
	                break;
	            }
	            T.key[i] = T.key[i-1];
	            T.value[i].gap = T.value[i-1].gap;
	            if(i==1){
	                T.key[0] = k;
	                T.value[0].gap = v;
	            }
	        }
	        T.m += 1;
	        return T;
	    }
	    else{
	        node next = T.rightnode;
	        int pos = T.m;
	        for(int i=0; i<T.m; i++){
	            if(k < T.key[i]){
	                next = T.left_child_node[i];
	                pos = i;
	                break;
	            }
	        }

	        next = insertion(next,k,v);

	        if(next.m == max_degree){
	            split(T,next,pos);
	        }
	        return T;
	    }
	}

	public static void in(node T,int k,int v){
		if(T == (node) null) {
	    	root = new node(k,v,true);
	    }
		else {
			T = insertion(T,k,v);
		    if(T.m == max_degree){
		        split((node) null,T,0);
		    }
		    return;
		}
	}
	
	public static void serch(node T,int k){
	    if(T.isleaf){
	        for(int i=0; i<T.m; i++){
	            if(T.key[i] == k){
	            	System.out.println(T.value[i].gap);
	                return;
	            }
	        }
	        System.out.println("NOT FOUND");
	    }
	    else{
	    	StringBuilder sb = new StringBuilder();
	        node next = T.rightnode;
	        for(int i=0; i<T.m; i++){
	            if(next == T.rightnode && k < T.key[i]) next = T.left_child_node[i];
	            sb.append(T.key[i]);
	            sb.append(",");
	        }
	        String str = sb.toString();
	        str = str.replaceAll(",$", "");
	        //str = str.substring(0,str.length()-1);
	        System.out.println(str);
	        serch(next,k);
	    }
	}

	public static node findpointer(node T,int k){
	    if(T.isleaf){
	        return T;
	    }
	    else{
	        node next = T.rightnode;
	        for(int i=0; i<T.m; i++){
	            if(k < T.key[i]){
	                next = T.left_child_node[i];
	                break;
	            }
	        }
	        return findpointer(next,k);
	    }
	}

	public static void range_serch(node T,int x,int y){
	    node L = findpointer(T,x);
	    node R = findpointer(T,y);
	    
	    for(int i=0; i<L.m; i++){
	    	if(x <= L.key[i] && L.key[i] <= y){
	    		StringBuilder sb = new StringBuilder();
	    		sb.append(L.key[i]);
	    		sb.append(",");
	    		sb.append(L.value[i].gap);
	    		System.out.println(sb);
	    	}
	    }

	    if(L == R) return;

	    L = L.rightnode;

	    while(true){
	        for(int i=0; i<L.m; i++){
	        	StringBuilder sb = new StringBuilder();
	    		sb.append(L.key[i]);
	    		sb.append(",");
	    		sb.append(L.value[i].gap);
	    		System.out.println(sb);
	        }
	        L = L.rightnode;
	        if(L == R) break;
	    }

	    for(int i=0; i<L.m; i++){
	            if(x <= L.key[i] && L.key[i] <= y) {
	            	StringBuilder sb = new StringBuilder();
		    		sb.append(L.key[i]);
		    		sb.append(",");
		    		sb.append(L.value[i].gap);
		    		System.out.println(sb);
	            }
	    }
	}

	public static node balance(node parent,node child,int pos){
	    if(child.m >= min_key) return parent; //굳이 조정 할 필요 없음
	    if(child.isleaf){
	        if(pos > 0 && parent.left_child_node[pos-1].m > min_key){ //왼쪽 형제에서 땡겨올수 있음
	            node sibling = parent.left_child_node[pos-1];
	            sibling.m -= 1;
	            for(int i=child.m; i>0; i--){
	                child.key[i] = child.key[i-1];
	                child.value[i].gap = child.value[i-1].gap;
	            }
	            child.key[0] = sibling.key[sibling.m];
	            child.value[0].gap = sibling.value[sibling.m].gap;
	            child.m += 1;
	            parent.key[pos-1] = child.key[0];
	            return parent;
	        }
	        if(pos < parent.m){
	            node sibling;
	            if(pos == parent.m - 1) sibling = parent.rightnode;
	            else sibling = parent.left_child_node[pos+1];
	            if(sibling.m > min_key){
	                child.key[child.m] = sibling.key[0];
	                child.value[child.m].gap = sibling.value[0].gap;
	                child.m += 1;
	                for(int i=1; i<sibling.m; i++){
	                    sibling.key[i-1] = sibling.key[i];
	                    sibling.value[i-1].gap = sibling.value[i].gap;
	                }
	                sibling.m -= 1;
	                parent.key[pos] = sibling.key[0];
	                return parent;
	            }
	        }
	        //형제들이 모두 거지면 merge해야됨
	        if(pos > 0){ //왼쪽 형제가 있으면 우선적으로 merge
	            node sibling = parent.left_child_node[pos-1];
	            for(int i=0; i<child.m; i++){
	                sibling.key[sibling.m + i] = child.key[i];
	                sibling.value[sibling.m + i].gap = child.value[i].gap;
	            }
	            sibling.m += child.m;
	            sibling.rightnode = child.rightnode;
	            for(int i=pos; i<parent.m - 1; i++){
	                parent.key[i] = parent.key[i+1];
	                parent.left_child_node[i] = parent.left_child_node[i+1];
	            }
	            if(sibling.rightnode != (node) null) parent.key[pos - 1] = sibling.rightnode.key[0];
	            if(pos == parent.m) parent.rightnode = sibling;
	            parent.m -= 1;
	            return parent;
	        }
	        else{
	            node sibling;
	            if(parent.m == 1) sibling = parent.rightnode;
	            else sibling = parent.left_child_node[1];

	            for(int i=0; i<sibling.m; i++){
	                child.key[child.m + i] = sibling.key[i];
	                child.value[child.m + i].gap = sibling.value[i].gap;
	            }
	            child.m += sibling.m;
	            child.rightnode = sibling.rightnode;

	            for(int i=1; i<parent.m - 1; i++){
	                parent.key[i] = parent.key[i+1];
	                parent.left_child_node[i] = parent.left_child_node[i+1];
	            }
	            parent.m -= 1;
	            if(parent.m != 0) parent.key[0] = child.rightnode.key[0];
	            return parent;
	        }
	    }
	    else{ //부모와 자식 모두 nonleaf
	        if(pos > 0 && parent.left_child_node[pos-1].m > min_key){ //왼쪽 자식에서 땡겨오기 가능
	            node sibling = parent.left_child_node[pos-1];
	            sibling.m -= 1;
	            for(int i=child.m; i>0; i--){
	                child.key[i] = child.key[i-1];
	                child.left_child_node[i] = child.left_child_node[i-1];
	            }
	            child.key[0] = parent.key[pos-1];
	            child.left_child_node[0] = sibling.rightnode;
	            child.m += 1;
	            parent.key[pos-1] = sibling.key[sibling.m];
	            sibling.rightnode = sibling.left_child_node[sibling.m];
	            return parent;
	        }
	        if(pos < parent.m){
	            node sibling;
	            if(pos == parent.m - 1) sibling = parent.rightnode;
	            else sibling = parent.left_child_node[pos+1];
	            if(sibling.m > min_key){
	                child.key[child.m] = parent.key[pos];
	                parent.key[pos] = sibling.key[0];
	                child.left_child_node[child.m] = child.rightnode;
	                child.rightnode = sibling.left_child_node[0];
	                child.m += 1;
	                sibling.m -= 1;
	                for(int i=0; i<sibling.m; i++){
	                    sibling.key[i] = sibling.key[i+1];
	                    sibling.left_child_node[i] = sibling.left_child_node[i+1];
	                }
	                return parent;
	            }
	        }
	        //빌려올수 없으면 merge
	        if(pos > 0){
	            node sibling = parent.left_child_node[pos-1];
	            sibling.key[sibling.m] = parent.key[pos-1];
	            sibling.left_child_node[sibling.m] = sibling.rightnode;
	            sibling.m += 1;
	            for(int i=0; i<child.m; i++){
	                sibling.key[sibling.m + i] = child.key[i];
	                sibling.left_child_node[sibling.m + i] = child.left_child_node[i];
	            }
	            sibling.m += child.m;
	            sibling.rightnode = child.rightnode;
	            parent.key[pos-1] = parent.key[pos];
	            parent.m -= 1;
	            for(int i=pos; i<parent.m; i++){
	                parent.key[i] = parent.key[i+1];
	                parent.left_child_node[i] = parent.left_child_node[i+1];
	            }
	            if(pos > parent.m) parent.rightnode = sibling;
	            return parent;
	        }
	        else{
	            node sibling;
	            if(parent.m == 1) sibling = parent.rightnode;
	            else sibling = parent.left_child_node[1];
	            child.key[child.m] = parent.key[0];
	            child.left_child_node[child.m] = child.rightnode;
	            child.m += 1;
	            for(int i=0; i<sibling.m; i++){
	                child.key[child.m + i] = sibling.key[i];
	                child.left_child_node[child.m + i] = sibling.left_child_node[i];
	            }
	            child.m += sibling.m;
	            child.rightnode = sibling.rightnode;
	            parent.m -= 1;
	            if(parent.m == 0) return parent;

	            parent.key[0] = parent.key[1];
	            for(int i=1; i<parent.m; i++){
	                parent.key[i] = parent.key[i+1];
	                parent.left_child_node[i] = parent.left_child_node[i+1];
	            }
	            return parent;
	        }
	    }
	}

	public static node deletion(node T,int k){
	    if(T.isleaf){
	        boolean isdel = false;
	        for(int i=0; i<T.m; i++){
	            if(k == T.key[i]){
	                for(int j=i+1; j<T.m; j++){
	                    T.key[j-1] = T.key[j];
	                    T.value[j-1].gap = T.value[j].gap;
	                }
	                isdel = true;
	                T.m -= 1;
	                break;
	            }
	        }
	        if(!isdel) System.out.println(k + " key deletion failed : not in tree");
	        return T;
	    }
	    else{
	        node next = T.rightnode;
	        int pos = T.m;
	        for(int i=0; i<T.m; i++){
	            if(k < T.key[i]){
	                next = T.left_child_node[i];
	                pos = i;
	                break;
	            }
	        }
	        
	        next = deletion(next,k);

	        balance(T,next,pos);

	        return T;
	    }
	}

	public static void change(node T,node nl,int pos,int k){
	    if(T.isleaf){
	        if(nl != (node) null) nl.key[pos] = T.key[0];
	        return;
	    }
	    else{
	        node next = T.rightnode;
	        for(int i=0; i<T.m; i++){
	            if(nl == (node) null && k == T.key[i]){
	                nl = T;
	                pos = i;
	            }
	            if(k < T.key[i]){
	                next = T.left_child_node[i];
	                break;
	            }
	        }
	        change(next,nl,pos,k);
	    }
	}

	public static void del(node T,int k){
		if(T == (node) null || T.m == 0) {
			System.out.println("deletion failed : empty tree");
			return;
		}
	    T = deletion(T,k);
	    if(T.m == 0 && !T.isleaf) T = T.left_child_node[0];
	    change(T,(node) null,0,k);
	    return;
	}
	
	public static void dfsgetnum(node T) {
		if(T.isleaf) {
			T.num = cnt++;
			return;
		}
		else {
			T.num = cnt++;
			for(int i=0; i<T.m; i++) {
				dfsgetnum(T.left_child_node[i]);
			}
			dfsgetnum(T.rightnode);
		}
	}
	
	public static void dfsgetstr(node T) {
		StringBuilder sb = new StringBuilder();
		sb.append(T.m);
		sb.append(" ");
		sb.append(T.isleaf);
		sb.append(" ");
		for(int i=0; i<T.m; i++) {
			sb.append(T.key[i]);
			sb.append(" ");
		}
		if(T.isleaf) {
			for(int i=0; i<T.m; i++) {
				sb.append(T.value[i].gap);
				sb.append(" ");
			}
			if(T.rightnode == (node) null) sb.append("0");
			else{
				String rightnum = Integer.toString(T.rightnode.num);
				sb.append(rightnum);
			}
		}
		else {
			for(int i=0; i<T.m; i++) {
				sb.append(T.left_child_node[i].num);
				sb.append(" ");
				dfsgetstr(T.left_child_node[i]);
			}
			String rightnum = Integer.toString(T.rightnode.num);
			sb.append(rightnum);
			dfsgetstr(T.rightnode);
		}
		sb.append("\n");
		outputstring[T.num] = sb.toString();
	}
	
	public static void main(String[] args) throws IOException{
		if(args[0].equals("-c")) { //새로운 파일 생성
			String index_file = args[1];
			BufferedOutputStream bs = new BufferedOutputStream(new FileOutputStream(index_file));
			bs.write(args[2].getBytes());
			bs.close();
		}
		else {
			//트리 불러오기
			String filePath = args[1]; // 대상 파일
	        FileInputStream fileStream = new FileInputStream(filePath);
	        
	        //버퍼 선언
	        byte[ ] readBuffer = new byte[fileStream.available()];
	        while (fileStream.read( readBuffer ) != -1){}
	        String readinfo = new String(readBuffer);
	        treeinfo = readinfo.split("\n");
	        fileStream.close(); //스트림 닫기
	        
	        //treeinfo로 트리 만들기 있으면 1번 줄이 root정보
	        max_degree = Integer.parseInt(treeinfo[0]);
	        min_key = (max_degree - 1)/2;
	        int nodenum = treeinfo.length - 1;
	        root = (node) null;
	        if(nodenum > 0) {
	        	adress = new node[nodenum+1];
	        	for(int i=1; i<=nodenum; i++) {
	        		adress[i] = new node(treeinfo[i]);
	        	}
	        	for(int i=1; i<=nodenum; i++) {
	        		connect(treeinfo[i],i);
	        	}
	        	root = adress[1];
	        }
	        if(args[0].equals("-s")) { //search
				int x = Integer.parseInt(args[2]);
				if(root == (node) null || root.m == 0) {
					System.out.println("search failed : empty tree");
				}
				else serch(root,x);
			}
			else if(args[0].equals("-r")) { //range search
				int x = Integer.parseInt(args[2]);
				int y = Integer.parseInt(args[3]);
				if(root == (node) null || root.m == 0) {
					System.out.println("range search failed : empty tree");
				}
				else range_serch(root,x,y);
			}
			else {
				if(args[0].equals("-i")) { //insertion
					//csv file 불러오기
					File file = new File(args[2]); // 현재 폴더의 디렉토리에 파일 저장해놓고 경로 지정.
					BufferedReader br = new BufferedReader(new BufferedReader(new FileReader(file))); //버퍼리더 만들기.
					String line = "";
					while ((line = br.readLine()) != null) { //한 라인씩 읽어오기.
						String csvinput[] = line.split(",");
						csvinput[0] = csvinput[0].replaceAll("[^\\d]", "");
						csvinput[1] = csvinput[1].replaceAll("[^\\d]", "");
						int inputkey = Integer.parseInt(csvinput[0]);
						int inputvalue = Integer.parseInt(csvinput[1]);
						in(root,inputkey,inputvalue);
					}
					br.close();
				}
				else if(args[0].equals("-d")) { //deletion
					//csv file 불러오기
					File file = new File(args[2]); // 현재 폴더의 디렉토리에 파일 저장해놓고 경로 지정.
					BufferedReader br = new BufferedReader(new BufferedReader(new FileReader(file))); //버퍼리더 만들기.
					String line = "";
					while ((line = br.readLine()) != null) { //한 라인씩 읽어오기.
						line = line.replaceAll("[^\\d]", "");
						int inputkey = Integer.parseInt(line);
						del(root,inputkey);
					}
					br.close();
				}
				
				//새로운 index.dat로 덮어쓰기
				String index_file = args[1];
				BufferedOutputStream bs = new BufferedOutputStream(new FileOutputStream(index_file));
				bs.write(treeinfo[0].getBytes()); //0번줄은 트리 크기
				bs.write("\n".getBytes());
				if(root == (node) null || root.m == 0) {} //트리 비어있으면 그냥 트리 크기만 저장하고 끝
				else{
					cnt = 1; //cnt = 1 부터 각 node에 임의의 번호를 부여
					dfsgetnum(root); //번호는 dfs로 부여
					outputstring = new String[cnt];
					dfsgetstr(root); //이후 번호를 기준으로 각 node 정보 저장
					for(int i=1; i<cnt; i++) {
						bs.write(outputstring[i].getBytes());
					}
				}
				bs.close();
			}
		}
    }
}