//  BOJ_1110_더하기사이클
//
//  Created by 한수빈 on 2023/02/06.
//

import Foundation

var input = readLine()
var num: Int = Int(input!)!
var count: Int = 0
var temp: Int = num

while(true){
    temp = (temp % 10) * 10 + (((temp / 10) + (temp % 10)) % 10)
    count += 1
    if temp == num {
        break
    }
}

print(count)
