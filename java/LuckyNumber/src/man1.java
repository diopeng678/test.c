import java.util.Random;
public class man1 {
    public static void main(String[] args) {
        int[] arr = new int[10];
        Random random = new Random();
// 生成10个1-100随机数
        for (int i = 0; i < arr.length; i++) {
            arr[i] = random.nextInt(100) + 1;
        }
// 输出数组
        System.out.println("数组元素：");
        for (int num : arr) {
            System.out.print(num + " ");
        }
// 找最大值及索引
        int max = arr[0];
        int index = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }
        System.out.println("\n 最大值：" + max + "，索引：" + index);
    }
}