function solution(nums) {
    const maxSelect = nums.length / 2;               // 선택 가능한 최대 수
    const uniqueKinds = new Set(nums).size;          // 고유한 폰켓몬 종류 수
    const answer = Math.min(maxSelect, uniqueKinds); // 가능한 최대 종류 수
    return answer;
}