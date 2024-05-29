#pragma once
namespace SimplifyPath
{
	/*
71. Simplify Path

Given an absolute path for a Unix-style file system, which begins with a slash '/', 
transform this path into its simplified 
canonical path.

In Unix-style file system context, a single period '.' signifies the current directory, 
a double period ".." denotes moving up one directory level, 
and multiple slashes such as "//" are interpreted as a single slash. 

In this problem, treat sequences of periods not covered by the previous rules (like "...") 
as valid names for files or directories.

The simplified canonical path should adhere to the following rules:

It must start with a single slash '/'.
Directories within the path should be separated by only one slash '/'.
It should not end with a slash '/', unless it's the root directory.
It should exclude any single or double periods used to denote current or parent directories.
Return the new path.



Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.


Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.

Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:
A double period ".." refers to the directory up a level.

Example 4:
Input: path = "/../"
Output: "/"
Explanation:
Going one level up from the root directory is not possible.

Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation:
"..." is a valid name for a directory in this problem.



Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
	*/
    class Solution {
    public:
        string simplifyPath(string path) 
        {
            vector<string> dir, ans_vec;
            /*
            The following split method was taken from https://www.javatpoint.com/how-to-split-strings-in-cpp
            Program3.cpp Please refer this for more details.
            */
            string T; // temp string to hold split value.
            stringstream x(path);
            while (getline(x, T, '/')) 
            {
                dir.push_back(T);
            }
            string ans = "";
            for (int i = 0; i < dir.size(); i++) 
            {
                if (dir[i] == "..") 
                {
                    if (ans_vec.size() > 0) // this is a fail check if we are on root directory then we can't move to previous dir.
                        ans_vec.pop_back();
                }
                else if (dir[i] == ".") 
                {
                    // stay on the current directory
                }
                else 
                {
                    if (dir[i] != "") // in case we have "//" where split method will return ""(emptyString) in this case we won't be putting it in our ans_vec.
                        ans_vec.push_back(dir[i]);
                }
            }
            for (int i = 0; i < ans_vec.size(); i++) 
            {
                // join all the remaining dir with '/'.
                ans += "/" + ans_vec[i];
            }
            // incase we don't have anything present in ans_dir then we'll simply return root directory.
            if (ans == "") 
                ans = "/";
            return ans;
        }
    };

	void process()
	{
        Solution sol;
		cout << sol.simplifyPath("/home/") << "\n"; // home
		cout << sol.simplifyPath("/home//foo/") << "\n"; // home
		cout << sol.simplifyPath("/home/user/Documents/../Pictures") << "\n"; // home
		cout << sol.simplifyPath("/../") << "\n"; // home
		cout << sol.simplifyPath("/.../a/../b/c/../d/./") << "\n"; // home


	}
}