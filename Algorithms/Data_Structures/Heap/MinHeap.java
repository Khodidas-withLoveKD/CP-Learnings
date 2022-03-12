package Algorithms.Data_Structures.Heap;

public class MinHeap {
  private static int size = -1;
  private static int[] heap;

  private static int parent (int pos) {
    return (pos - 1) / 2;
  }
  private static void swap (int newIndex, int oldIndex) {
    int temp = heap[oldIndex];
    heap[oldIndex] = heap[newIndex];
    heap[newIndex] = temp;
  }
  private static void insertAtCorrectPlace (int element, int currentPos) {
    while (heap[currentPos] < heap[parent(currentPos)]) {
      swap (currentPos, parent(currentPos));
      currentPos = parent(currentPos);
    }
  }
  private static void insert (int element) {
    heap[++size] = element;

    // insert at correct order
    insertAtCorrectPlace(element, size);
//    printHeap();
  }
  private static void printHeap () {
    for (int i = 0; i < Math.log(heap.length); i++) {

    }
  }
  public static void main(String[] args) {
    heap = new int[10];
    // insert
    insert(1);
    insert(7);
    insert(3);
    insert(9);
    insert(10);
    insert(5);
    insert(1);
    insert(8);
    insert(2);
    insert(6);
    printHeap();

  }
}
