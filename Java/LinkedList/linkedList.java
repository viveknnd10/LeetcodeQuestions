package Java.LinkedList;
public class linkedList {
    static class node{
        int val;
        node next;
        node(int data){
            this.val=data;
            this.next=null;
        }
    }
    private static node front=null;
    private static node rear=null;
    linkedList(){
    }
    public void add(int val)
    {
        node n=new node(val);
        if(front==null)
        {
            front=n;
            rear=n;
        }
        else{
            rear.next=n;
            rear=rear.next;
        }
    }
    public void printlist(){
        node current=front;
        while(current!=null)
        {
            System.out.print(current.val+" ");
            current=current.next;
        }
    }
}