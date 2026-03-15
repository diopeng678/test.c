public class ex03 {
    public static void main(String[] args) {
        // 字符型数据可以参与算术运算，以其对应的Unicode(ASCII)码值参与算术运算
        System.out.println('a');
        System.out.println('a' + 1);
        
        // 字符串参与运算
        System.out.println("hello" + 'a' + 1);
        System.out.println('a' + 1 + "hello");
        System.out.println("5+5=" + 5 + 5);
        System.out.println(5 + 5 + "=5+5");
    }
}