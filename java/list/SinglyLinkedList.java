public class SinglyLinkedList {

    public class Node<E> {
        E value;
        Node<E> next;

        Node (E value, Node<E> next) {
            this.value = value;
            this.next = next;
        }
    }

    private Node<E> head;
    private Node<E> cur;

    public E search(E obj, Comparator<? extends E> c) {
        Node<E> p = head;
        while (p != null) {
            if (c.compare(obj, p.value) == 0) {
                cur = p;
                return p.value;
            }
            p = p.next;
        }
        return null;
    }

    public void addFirst(E obj) {
        Node<E> p = head;
        head = cur = new Node<E>(obj, p);
    }

    public boolean next() {
        if (cur == null || cur.next == null) {
            return false;
        }
        cur = cur.next;
        return true;
    }

    public void printCurNode() {
        if (cur == null) {
            System.out.println("There is no value");
        } else {
            System.out.println(cur.value);
        }
    }
}
