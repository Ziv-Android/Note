public class HelloWorld {
    public static void main(String[] args) {
        float random = (float) (Math.round(Math.random() * 20)) / 100;
        System.out.println("Hello world" + random);

        float tem = 10.01F * 10 % 10;
        System.out.println("Test: " + tem);

        float time = System.currentTimeMillis();
        int timeS = (int) (time / 60000);
        System.out.println("Test: " + String.valueOf(time) + " -> " + timeS);
    }
}
