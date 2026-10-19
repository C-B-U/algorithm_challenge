import java.io.*;
import java.util.*;

public class Day_06 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] tailValues = new int[n];
        int[] tailIndices = new int[n];
        int[] parent = new int[n];
        Arrays.fill(parent, -1);

        int len = 0;

        for (int i = 0; i < n; i++) {
            int x = arr[i];
            int idx = upperBound(tailValues, len, x);

            tailValues[idx] = x;
            tailIndices[idx] = i;

            if (idx > 0) {
                parent[i] = tailIndices[idx - 1];
            }

            if (idx == len) {
                len++;
            }
        }

        int minChanges = n - len;
        System.out.println(minChanges);

        int[] lndsIndices = new int[len];
        int curr = tailIndices[len - 1];
        for (int i = len - 1; i >= 0; i--) {
            lndsIndices[i] = curr;
            curr = parent[curr];
        }

        int[] result = arr.clone();

        for (int i = 0; i <= len; i++) {
            int startIdx = (i == 0) ? 0 : lndsIndices[i - 1] + 1;
            int endIdx = (i == len) ? n - 1 : lndsIndices[i] - 1;

            if (startIdx > endIdx) continue;

            if (i == 0) {
                int fillVal = arr[lndsIndices[0]];
                for (int j = startIdx; j <= endIdx; j++) {
                    result[j] = fillVal;
                }
            } else if (i == len) {
                int fillVal = arr[lndsIndices[len - 1]];
                for (int j = startIdx; j <= endIdx; j++) {
                    result[j] = fillVal;
                }
            } else {
                int fillVal = arr[lndsIndices[i - 1]];
                for (int j = startIdx; j <= endIdx; j++) {
                    result[j] = fillVal;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(result[i]).append(i == n - 1 ? "" : " ");
        }
        System.out.println(sb.toString());
    }

    private static int upperBound(int[] a, int length, int key) {
        int low = 0, high = length;
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (a[mid] <= key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
