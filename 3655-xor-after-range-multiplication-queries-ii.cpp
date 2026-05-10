import "math"

    func xorAfterQueries(nums[] int, queries[][] int) int{
        const MOD = 1_000_000_007 n: = len(nums)
            B: = int(math.Sqrt(float64(n))) + 1

                     powMod: = func(base, exp, mod int) int{
                         res: = 1 base %= mod for exp> 0 {
                             if exp & 1 == 1 {res = res * base % mod } base = base * base % mod exp >>= 1 } return res } inv: = func(a int) int{return powMod(a, MOD - 2, MOD) }

                                                                                                                                                diff: = make([][] int, B + 1) for k: = 1;
k <= B;
k++
{
        diff[k] = make([]int, n+1)
        for i := range diff[k] { diff[k][i] = 1 }
}

    for
        _, q : = range queries
        {
            l, r, k, v : = q[0], q[1], q[2], q[3] if k > B
            {
            for
            idx:
                = l;
            idx <= r;
            idx += k
            {
                nums[idx] = nums[idx] * v % MOD
            }
            }
            else
            {
            last:
                = l + ((r - l) / k) * k
                                          diff[k][l] = diff[k][l] * v % MOD if last + k < n
                {
                    diff[k][last + k] = diff[k][last + k] * inv(v) % MOD
                }
            }
        }

    mult := make([]int, n)
    for i := range mult { mult[i] = 1 }

    for k := 1;
    k <= B;
    k++
    {
        for
        r:
            = 0;
        r < k;
        r++
        {
        cur:= 1
            for idx := r;
            idx < n;
            idx += k
            {
                cur = cur * diff[k][idx] % MOD mult[idx] = mult[idx] * cur % MOD
            }
        }
    }

    ans := 0
    for i := 0;
    i < n;
    i++
    {
        ans ^= nums[i] * mult[i] % MOD
    }
    return ans
    }