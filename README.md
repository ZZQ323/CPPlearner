# Code-snippets




$$
\left\{ 
\begin{array}{c}
	f_5\cos 45\degree+f_6=f_9\cos 45\degree+f_{10}\\
	f_5\sin 45\degree+f_7+f_9\sin 45\degree=15\\
	f_1=f_6\\
	f_3=10\\
	f_1\cos 45\degree=f_4+f_5\cos 45\degree\\
	f_1\sin 45\degree+f_3+f_5\sin 45\degree=0\\
	f_4=f_8\\
	f_7=0\\
	f_5\cos 45\degree+f_6=f_9\cos 45\degree+f_10\\
	f_5\sin 45\degree+f_7+f_9\sin 45\degree=15\\
	f_{10}=f_{13}\\
	{f_1}_1=20\\
	f_8+f_9\cos 45\degree={f_1}_2\cos 45\degree\\
	{f_1}_3+{f_1}_2\sin 45\degree=0\\
\end{array} 
\right. 
$$


给定一个序列，序列编号从 1 到 N 。每个编号上都有一个值，代表该编号的颜色。编号的颜色总共有 K 种，编号的颜色从 1 到 K 。第 i 个编号的颜色为 Ai。Fi 表示恰好有 i 种颜色的子串数量。请计算$(\sum_{i=1}^n*(F_i * 131^i)) mod (10^9 + 7)$

注意：mod 代表取模； 子串是序列中的任意一段连续区间