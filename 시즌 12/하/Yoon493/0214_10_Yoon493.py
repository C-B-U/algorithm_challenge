S = str(input())

CHOSUNG_LIST = ["ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]

chosung = ""
for char in S:
    if "가" <= char <= "힣":  # 한글 범위 확인
        unicode_val = ord(char) - 0xAC00
        chosung_idx = unicode_val // (21 * 28)  # 초성 인덱스 계산
        chosung += CHOSUNG_LIST[chosung_idx]

print(chosung)