class Solution {
public:
    string intToRoman(int num) {
        string res;
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thous[] = {"", "M", "MM", "MMM"}; 
        res.append(thous[num/1000]);
        res.append(huns[(num%1000)/100]);
        res.append(tens[(num%100)/10]);
        res.append(ones[num%10]);
        return res;
    }
};