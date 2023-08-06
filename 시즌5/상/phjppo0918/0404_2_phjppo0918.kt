import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))) {
    val caseSize: Int = readLine().toInt()
    val allPq = PriorityQueue<Study>()
    val partPq = PriorityQueue<Long>()

    var st : StringTokenizer
    for (i in 0 until caseSize) {
        st = StringTokenizer(readLine())
        allPq.add(Study(st.nextToken().toLong(), st.nextToken().toLong()))
    }

    var count = 1;
    val first = allPq.poll();
    partPq.add(first.end)
    while (allPq.isNotEmpty()) {
        val next = allPq.poll()
        if(next.start >= partPq.peek()) {
            partPq.poll()
        }
        partPq.add(next.end)
    }

    println(partPq.size)
}

class Study(val start: Long, val end: Long) : Comparable<Study> {
    override fun compareTo(other: Study): Int {
        if (start == other.start) {
            return (end - other.end).toInt();
        }
        return (start - other.start).toInt()
    }

}