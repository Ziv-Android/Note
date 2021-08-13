public class HelloWorld {
    public static void main(String[] args) {
        float random = (float) (Math.round(Math.random() * 20)) / 100;
        System.out.print("Hello world" + random);

        float tem = 10.01F * 10 % 10;
        System.out.print("Test: " + tem);
    }
}
