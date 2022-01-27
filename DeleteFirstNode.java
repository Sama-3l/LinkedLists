import java.util.*;
class Node{
    Node objf, objb;
    int a;
    void setUp(Node obj1, Node obj2, int b){
        objf = obj1;
        objb = obj2;
        a = b;
    }

    Node print(){
        System.out.print(a);
        return objf;
    }

    Node delete_first(Node obj){
        obj.objf.objb = null;
        return obj.objf;
    }
}

class DeleteInsertion{
    public static void main(String args[]){
        Node obj = new Node();
        Node objb = null;
        Node head = obj;
        Node last = obj;
        Scanner sc = new Scanner(System.in);
        int p = 1, b;
        System.out.println(obj);
        System.out.println("No shit sherlock");
        do{
            Node objf = new Node();
            System.out.println("Enter number");
            b = sc.nextInt();
            System.out.println("More numbers? Enter 0 is no. 1 for yes");
            p = sc.nextInt();
            if(p != 0){
                obj.setUp(objf, objb, b);
            }
            else{
                obj.setUp(null, objb, b);
                last = obj;
            }
            objb = obj;
            obj = objf;
        }while(p != 0);
        Node delete = new Node();
        obj = delete.delete_first(head);
        while(obj != null){
            if(obj.objf != null){
                System.out.print(obj.a + " --> ");
            }
            else{
                System.out.println(obj.a);
            }
            obj = obj.objf;  
        }
        obj = last;
        while(obj != null){
            if(obj.objb != null){
                System.out.print(obj.a + " --> ");
            }
            else{
                System.out.println(obj.a);
            }
            obj = obj.objb;
        }
    }
}
