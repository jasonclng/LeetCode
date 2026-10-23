import java.util.Arrays;

public class Main {
    private static int depthOf(String seq, int[] answer, int group) {
        int depth = 0, maxDepth = 0;

        for (int i = 0; i < seq.length(); i++) {
            if (group >= 0 && answer[i] != group) {
                continue;
            }
            depth += seq.charAt(i) == '(' ? 1 : -1;
            if (depth < 0) {
                return -1;
            }
            maxDepth = Math.max(maxDepth, depth);
        }

        return depth == 0 ? maxDepth : -1;
    }

    private static boolean isValidSplit(String seq, int[] answer) {
        if (answer == null || answer.length != seq.length()) {
            return false;
        }
        for (int value : answer) {
            if (value != 0 && value != 1) {
                return false;
            }
        }

        int depthA = depthOf(seq, answer, 0);
        int depthB = depthOf(seq, answer, 1);
        int best = (depthOf(seq, answer, -1) + 1) / 2;

        return depthA >= 0 && depthB >= 0 && Math.max(depthA, depthB) == best;
    }

    public static void main(String[] args) {
        String[] cases = { "(()())", "()(())()", "()", "((((()))))", "()()()" };
        int failures = 0;

        for (String seq : cases) {
            int[] answer = new Solution().maxDepthAfterSplit(seq);
            boolean passed = isValidSplit(seq, answer);

            System.out.printf("%-12s %s %s%n", seq,
                    Arrays.toString(answer).replace(" ", ""), passed ? "PASS" : "FAIL");

            if (!passed) {
                failures++;
            }
        }

        System.exit(failures == 0 ? 0 : 1);
    }
}
