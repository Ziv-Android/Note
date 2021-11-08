import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class HelloWorld {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>(Arrays.asList("/", "+", "="));
        for (int i = 0; i < 10; i++) {
            list.add("" + i);
        }
        for (char i = 'a'; i <= 'z'; i++) {
            list.add("" + i);
        }
        for (char i = 'A'; i <= 'Z'; i++) {
            list.add("" + i);
        }
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }

    private static void mathTest() {
        // 随机数
        // round -> [0.0, 1.0)
        float random = (float) (Math.round(Math.random() * 20)) / 100;
        System.out.println("Hello world: " + random);
        float random3 = 36.3F + (float) (Math.round(Math.random() * 50)) / 100;
        System.out.println("Hello world3: " + random3);
        float number = 12.34555F;
        DecimalFormat decimalFormat = new DecimalFormat(".00");
        String price = decimalFormat.format(number);
        System.out.println("Hello world4: " + price);
        int max = 20, min = 5;
        // nextInt -> [5, 20)
        int random2 = new Random().nextInt((max - min) + 1) + min;
        System.out.println("Hello world: " + random2);
        int[] arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ThreadLocalRandom.current().nextInt(min, max + 1);
            // System.out.println("Hello world: " + arr[i]);
        }
        
        // 小数点后一位
        int tem = (int)(10.01F * 10 % 10);
        System.out.println("Test: " + tem);

        // 毫秒 -> 分
        long time = System.currentTimeMillis();
        int timeS = (int) (time / 60000);
        System.out.println("Test: " + String.valueOf(time) + " -> " + timeS);


        System.out.println("Test: " + String.valueOf(nowToActual(34F)));

        System.out.println("Test: " + String.valueOf(temp(28F, 36F, 1F)));
    }

    public static float nowToActual(float t){
        if (t>27){
            t+=2.4;
        }else if (t>=32.8 && t<33.8){
            t+=2.3;
        }else if (t>=33.8 && t<34.2){
            t+=2.2;
        }else if (t>=34.2 && t<35){
            t+=2.1;
        }
        double v = -0.000125 * Math.pow(t, 6) + 0.0283429488 * Math.pow(t, 5) - 2.67004808 * Math.pow(t, 4)
                + 133.762569 * Math.pow(t, 3) - 3758.41829 * Math.pow(t, 2) + 56155.4892 * t
                - 348548.755 + t;
        return (float) v;
    }

    public static double temp(float ht, float ct, float distance) {
        System.out.println("temp: " + String.valueOf(Math.pow(ct + 273.15, 4)));
        System.out.println("temp: " + String.valueOf(Math.pow(ht + 273.15, 4)));
        System.out.println("temp: " + String.valueOf(Math.exp(0.1 * distance)));
        double temp = (0.95 * (Math.pow(ct + 273.15, 4) - Math.pow(ht + 273.15, 4)) / 0.95) * Math.exp(0.1 * distance);
        System.out.println("temp: " + String.valueOf(temp));
        double tempSqrt = Math.sqrt(temp);
        System.out.println("temp: " + String.valueOf(tempSqrt));
        System.out.println("temp: " + String.valueOf(Math.sqrt(tempSqrt)));
        System.out.println("temp: " + String.valueOf(Math.sqrt(tempSqrt) - 273.15));
        return Math.pow(temp, 1/4);
    }

}
