import java.util.HashMap;

public class Main166 {
    public String fractionToDecimal(int numerator, int denominator) {
        long a = numerator;
        long b = denominator;
        StringBuilder result = new StringBuilder();
        if (a * b < 0) {
            result.append("-");
        }
        a = Math.abs(a);
        b = Math.abs(b);
        result.append(a / b);
        long remainder = a % b;
        if (remainder == 0) {
            return result.toString();
        }
        result.append(".");
        HashMap<Long, Integer> remainderIndexMap = new HashMap<>();
        while (remainder != 0 && !remainderIndexMap.containsKey(remainder)) {
            remainderIndexMap.put(remainder, result.length());
            result.append(remainder * 10 / b);
            remainder = remainder * 10 % b;
        }
        if (remainder == 0) {
            return result.toString();
        } else {
            return result.insert(remainderIndexMap.get(remainder), "(").append(")").toString();
        }
    }
}
