public class man {
    public static void main(String args[]) {
        byte b1 = 3;
        byte b2 = 4;
        byte b3 = (byte)(b1 + b2); // 强制类型转换
        byte b4 = 3 + 4;
        int b5 = 120 + 20; // 改为int类型

        short s = 1;
        s = (short)(s + 1);
        System.err.println("b1" + b1); // 强制类型转换
        // s += 1; // 复合赋值运算符，自动强制类型转换
    }
}