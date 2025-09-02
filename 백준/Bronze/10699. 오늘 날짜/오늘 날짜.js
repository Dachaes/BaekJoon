const date = new Date();
const koreaDate = new Date(date.toLocaleString("en-US", { timeZone: "Asia/Seoul" }));

const year = koreaDate.getFullYear();
const month = String(koreaDate.getMonth() + 1).padStart(2, '0');
const day = String(koreaDate.getDate()).padStart(2, '0');

console.log(`${year}-${month}-${day}`);