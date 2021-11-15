/**
 * Question4
 */
public class Question4 {
    public static void main(String[] args) {
        SuperClass superClass = new SubClass();
        printHello(superClass);
    }

    // 调用的SuperClass函数，但返回值为SubClass.getName()
    public static void printHello(SuperClass superClass) {
        System.out.println("Hello " + superClass.getName());
    }

    public static void printHello(SubClass subClass) {
        System.out.println("Hello " + subClass.getName());
    }
}

class SuperClass {
    public String getName() {
        return "Super";
    }
}

class SubClass extends SuperClass {
    @Override
    public String getName() {
        return "Sub";
    }
}