//67. Add Binary https://leetcode.com/problems/add-binary/


// my first attempt. It was so long and it took 40 min and it's not working well
// I need to think simpler and I need to find patters. I need to see how things actually work 
// and how I can implement it

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string longer = a.length() > b.length() ? a : b;
//         string shorter = a.length() < b.length() ? a : b;
//         int shorterLen = shorter.length();
//         vector<char> reversedRes;
//         bool carry = false;
        
//         for(int i = 0; i < shorterLen; i++) {
//             int lDigit = longer[longer.length() - i] - '0';
//             int sDigit = shorter[shorter.length() - i] - '0';
            
//             if(lDigit == 0 && sDigit == 0 && carry) {
//                 reversedRes.push_back('1');
//                 carry = false;
//             }
//             else if(lDigit == 0 && sDigit == 0 && !carry) {
//                 reversedRes.push_back('0');
//             }
//             else if((lDigit + sDigit) == 1 && carry) {
//                 reversedRes.push_back('0');
//                 // there is a carry so we didn't make carry false
//             }
//             else if((lDigit + sDigit) == 1 && !carry) {
//                 reversedRes.push_back('1');
//                 carry = false;
//             }
//             else if(lDigit + sDigit == 2 && carry) {
//                 reversedRes.push_back('1');
//             }
//             else if(lDigit + sDigit == 2 && !carry) {
//                 reversedRes.push_back('0');
//                 carry = true;
//             }
//         }
//         for(int i = longer.length() - shorterLen - 1; i >= 0; i--) {
//             int lDigit = longer[longer.length() - i - shorterLen] -'0';

//             // lDigit == 1 
//             if(lDigit && carry && i != 0) {
//                 reversedRes.push_back('0');
//             }
//             else if(lDigit && carry && i == 0) {
//                 reversedRes.push_back('0');
//                 reversedRes.push_back('1');  // the last carry
//                 break;
//             }
//             else if(lDigit && !carry) {
//                 reversedRes.push_back('1');
//                 carry = false;
//             }

//             // lDigit == 0

//             else if(!lDigit && carry) {
//                 reversedRes.push_back('1');
//                 carry = false;
//             }
//             else if(!lDigit && !carry) {
//                 reversedRes.push_back('0');
//                 carry = false;
//             }
//         }

//         // reverse the vector<char> reversedRes
//         string finalString("");

//         for(int i = reversedRes.size() - 1; i >= 0; i--) {
//             finalString+= reversedRes[i];
//         }

//         return finalString;

//     }
// };

// 2ND ATTEMPT AND SOLUTION

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());

        return result;
    
    }
};