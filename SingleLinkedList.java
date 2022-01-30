import java.util.*;
class Node{
    Node objj, ro;
    int a;
    Node setUp(Node obj, int b){
        objj = obj;
        a = b;
        return objj;
    }

    Node print(){
        System.out.print(a);
        return objj;
    }
}


class SingleLinkedList{

    public static void main(String args[]){
        Node obj = new Node();
        Node head = obj;
        Scanner sc = new Scanner(System.in);
        int p = 1, b;
        System.out.println(obj);
        System.out.println("No shit sherlock");
        while(p != 0){
            Node obj1 = new Node();
            System.out.println("Enter number: ");
            b = sc.nextInt();
            System.out.println("More numbers? If not enter 0");
            p = sc.nextInt();
            if(p == 0){
                obj1 = obj.setUp(obj1, b);
                obj = obj1;
                obj1 = obj.setUp(null, b);
            }
            else{
                obj1 = obj.setUp(obj1, b);
                obj = obj1;
            }
        }
        obj = head;
        System.out.println("");
        while(obj.objj != null){
            obj = obj.print();
            if(obj.objj != null){
                System.out.print("->");
            }
            else{
                System.out.println("");
            }
        }
        sc.close();
    }
}