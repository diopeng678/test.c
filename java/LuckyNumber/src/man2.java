public class man2 {
    public static void main(String[] args) {
        long[] fib = new long[30];
        fib[0] = 1;
        fib[1] = 1;
// 计算斐波那契
        for (int i = 2; i < fib.length; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
// 输出
        System.out.println("斐波那契前 30 项：");
        for (int i = 0; i < fib.length; i++) {
            System.out.print(fib[i] + " ");
            if ((i + 1) % 5 == 0) System.out.println();
        }
    }
}