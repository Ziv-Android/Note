import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class HelloWorld {
    public static void main(String[] args) {
        // 随机数
        // round -> [0.0, 1.0)
        float random = (float) (Math.round(Math.random() * 20)) / 100;
        System.out.println("Hello world: " + random);
        int max = 20, min = 5;
        // nextInt -> [5, 20)
        int random2 = new Random().nextInt((max - min) + 1) + min;
        System.out.println("Hello world: " + random2);
        int[] arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ThreadLocalRandom.current().nextInt(min, max + 1);
            System.out.println("Hello world: " + arr[i]);
        }
        
        // 小数点后一位
        int tem = (int)(10.01F * 10 % 10);
        System.out.println("Test: " + tem);

        // 毫秒 -> 分
        long time = System.currentTimeMillis();
        int timeS = (int) (time / 60000);
        System.out.println("Test: " + String.valueOf(time) + " -> " + timeS);
    }
}
