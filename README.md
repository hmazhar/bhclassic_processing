Compiling
===========
- Requires Partio [https://github.com/wdas/partio/]
- Requires zlib (availible in most linux distributions and homebrew

Install from source or from favorite package manager/repo if availible.
- On mac use brew:
<pre><code>brew install zlib partio
</code></pre>

Use cmake to generate make files and then run make


bhclassic_to_ascii
===========

Convert a bhclassic point cloud to a ascii file

Arguments:
- Input_Filename 
- Output_Filename 
- Delimiter_(optional)

<pre><code>//with custom delimiter
bhclassic_to_ascii input.bhclassic output.txt ,
//without custom delimiter, default is space
bhclassic_to_ascii input.bhclassic output.txt
</code></pre>


Currently outputs position of every point in x y z format with an optional delimiter. 
