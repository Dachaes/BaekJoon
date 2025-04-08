function solution(str1, str2) {
    var answer = '';
    
    answer = [...str1].map((str, idx) => str + str2[idx]).join("");
    
    return answer;
}