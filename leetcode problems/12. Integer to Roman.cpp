public class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
             int value = getRoman(num, sb);
            num -= value;
        }
        return sb.toString();
    }

    private int getRoman(int num, StringBuilder sb) {
        if (num >= 1000) {
            sb.append('M');
            return 1000;
        }
         else if (num >= 900) {
             sb.append('C');
             return -100;
         }
         else if (num >= 500) {
             sb.append('D');
             return 500;
         }
         else if (num >= 400) {
             sb.append('C');
             return -100;
         }
         else if (num >= 100) {
             sb.append('C');
             return 100;
         }
         else if (num >= 90) {
             sb.append('X');
             return -10;
         }
         else if (num >= 50) {
             sb.append('L');
             return 50;
         }
         else if (num >= 40) {
             sb.append('X');
             return -10;
         }
         else if (num >= 10) {
             sb.append('X');
             return 10;
         }
         else if (num >= 9) {
             sb.append('I');
             return -1;
         }
         else if (num >= 5) {
             sb.append('V');
             return 5;
         }
         else if (num >= 4){
             sb.append('I');
             return -1;
         }
         else {
             sb.append('I');
             return 1;
         }
     }
 }
