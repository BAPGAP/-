public static void print(node T){
	    if(T == (node)null) System.out.println("nothing!!\n");
	    else{
	    	System.out.println("size : " + T.m);
	        if(T.isleaf){
	        	System.out.println("i am leaf");
	            for(int i=0; i<T.m; i++){
	            	System.out.print("key : " + T.key[i] + " value : " + T.value[i].gap + "   ");
	            }
	            System.out.println("");
	            if(T.rightnode == (node) null) System.out.println("i dont have sibling");
	            else System.out.println("i have sibling and it starts with " + T.rightnode.key[0]);
	        }
	        else{
	        	System.out.println("i am not leaf");
	            for(int i=0; i<T.m; i++){
	            	System.out.print("key : " + T.key[i] + "   ");
	            }
	            System.out.println("");
	            for(int i=0; i<T.m; i++){
	                print(T.left_child_node[i]);
	            }
	            print(T.rightnode);
	        }
	    }
	}