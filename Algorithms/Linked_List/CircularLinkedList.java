package Algorithms.Linked_List;

class CircularLinkedList {

public static void main(String[] args){
    Node one = new Node(1);
    Node two = new Node(2);
    Node three = new Node(3);
    one.next = two;
    two.next = three;

    Node head = one;
    while (head != null) {
        System.out.println(head.val);
        head = head.next;
    }
}
        }
