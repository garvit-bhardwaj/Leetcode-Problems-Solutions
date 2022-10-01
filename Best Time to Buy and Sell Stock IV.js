/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function (k, prices) {
	const n = prices.length;
	const memo = Array(n)
		.fill()
		.map(() =>
			Array(k + 1)
				.fill()
				.map(() => Array(2).fill(-1))
		);

	const dp = (idx, cnt, have) => {
		if (idx === n) return 0;

		ret = memo[idx][cnt][have];
		if (~ret) return ret;

		ret = dp(idx + 1, cnt, have);

		if (!have && cnt < k)
			ret = Math.max(ret, -prices[idx] + dp(idx + 1, cnt + 1, 1));

		if (have) ret = Math.max(ret, prices[idx] + dp(idx + 1, cnt, 0));

		memo[idx][cnt][have] = ret;

		return memo[idx][cnt][have];
	};

	const ans = dp(0, 0, 0);
	return ans;
};
