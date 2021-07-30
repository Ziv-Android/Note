public class InnerClass {
    
}

interface Displayanle {
    void display();

    default int add(int a, int b) {
        return a + b;
    } 
}

abstract class AbsDisplayClass {
    abstract void display();

    int add(int a, int b) {
        return a + b;
    }
}