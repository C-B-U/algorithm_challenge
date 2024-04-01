import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		List<Integer> cranes = new ArrayList<>();
		List<Integer> boxes = new ArrayList<>();

		int n = Integer.parseInt(bf.readLine());

		String[] tmp = bf.readLine().split(" ");
		for (int i = 0; i < n; i++){
			cranes.add(Integer.parseInt(tmp[i]));
        }

		int m = Integer.parseInt(bf.readLine());
		tmp = bf.readLine().split(" ");
		for (int i = 0; i < m; i++) {
			boxes.add(Integer.parseInt(tmp[i]));
        }
        
        cranes.sort(Collections.reverseOrder());
        boxes.sort(Collections.reverseOrder());

		if (boxes.get(0) > cranes.get(0)) {
			System.out.println(-1);
		} else {
			int time = 0;
			while (!boxes.isEmpty()) {
				time++;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < boxes.size(); ++j) {
						if (cranes.get(i) >= boxes.get(j)) {
							boxes.remove(j);
							break;
						}
					}
				}
			}
			System.out.println(time);
		}
	}
}
