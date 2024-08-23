import java.util.HashMap;

public class Main299 {
    public String getHint(String secret, String guess) {
        int[] countSecret = new int[10];
        int[] countGuess = new int[10];
        int lenght = secret.length();
        int bulls = 0;
        for (int i = 0; i < lenght; i++) {
            countSecret[secret.charAt(i) - '0']++;
            countGuess[guess.charAt(i) - '0']++;
            if (secret.charAt(i) == guess.charAt(i)) {
                bulls++;
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += Math.min(countSecret[i], countGuess[i]);
        }
        cows -= bulls;
        return bulls + "A" + cows + "B";
    }
}
