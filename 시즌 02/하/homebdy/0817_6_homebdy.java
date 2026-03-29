import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Queue {

    private int[] queue;
    private int rear;
    private int front;

    public Queue(int size) {
        this.queue = new int[size*3];
        this.rear = 0;
        this.front = 0;
    }

    public boolean offer(int x) {
        if (rear ==  queue.length*3) {
            return false;
        }
        queue[rear++] = x;
        return true;
    }

    public int poll() {
        if (front == rear) {
            return -1;
        }
        int value = queue[front++];
        return value;
    }

    public int size() {
        return rear - front;
    }
}

class homebdy_6 {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(bufferedReader.readLine());
        Queue queue = new Queue(num);

        for (int i = 1; i < num + 1; i++) {
            queue.offer(i);
        }

        while (queue.size() > 1) {
            queue.poll();
            queue.offer(queue.poll());
        }
        System.out.println(queue.poll());
    }
}