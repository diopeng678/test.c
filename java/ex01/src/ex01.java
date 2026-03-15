public class ex01 {
    public static void main(String[] args) {
        boolean flag = true;  // 声明boolean型变量并赋值
        char c1, c2;          // 声明char型变量
        c1 = '\u0041';        // 为char型变量赋值
        c2 = 'B';             // 为char型变量赋值
        int x;                // 声明int型变量
        x = 9;                // 为int型变量赋值
        int y = x;            // 声明并初始化int型变量
        //看看下面两个定义有没有区别呢?
        float f1 = (float)12.345;
        float f2 = 12.345f;   // 声明float型变量并赋值
        double d = 3.1415926;  //声明double型变量并赋值
        System.out.println("c1 = " + c1);
        System.out.println("c2 = " + c2);
        System.out.println("x = " + x);
        System.out.println("y = " + y);
        System.out.println("f1 = " + f1);
        System.out.println("f2 = " + f2);
        System.out.println("d = " + d);
    }
}