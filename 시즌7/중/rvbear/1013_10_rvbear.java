import java.io.*;
import java.util.*;

class Room implements Comparable<Room> {
    int start, end;

    public Room(int _start, int _end) {
        start = _start; end = _end;
    }

    @Override
    public int compareTo(Room r) {
        return this.start == r.start ? this.end - r.end : this.start - r.start;
    }
}
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Room[] rooms = new Room[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(stk.nextToken());
            int t = Integer.parseInt(stk.nextToken());
            rooms[i] = new Room(s, t);
        }

        Arrays.sort(rooms);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(rooms[0].end);
        for(int i = 1; i < n; i++) {
            if(pq.peek() <= rooms[i].start) {
                pq.poll();
            }
            pq.offer(rooms[i].end);
        }

        System.out.println(pq.size());
        br.close();
    }
}