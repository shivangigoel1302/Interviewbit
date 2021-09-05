string Solution::multiply(string nums1, string nums2) {
    int k=0;
        string s1="";
if(nums2=="0" || nums1=="0")return "0";
        for(int i=nums2.length()-1;i>=0;i--)
        {
            string s="";
            int t=k;
            while(t)
            {
                s+='0';
                t--;
            }
            int c=0;
            for(int j=nums1.length()-1;j>=0;j--)
            {
                int k1=(nums1[j]-'0')*(nums2[i]-'0')+c;
               // cout<<k1%10+c<<" "<<endl;
                s+=to_string(k1%10);
                c=k1/10;
            }
            if(c)s+=to_string(c);
            k++;
            int c1=0;


            string s2="";
            for(int i=0;i<max(s1.length(),s.length());i++)
            {
            int k1=0;
           if(s.length()>i)k1+=(s[i]-'0');
                if(s1.length()>i)k1+=(s1[i]-'0');
               if(c1)k1+=c1;
               s2+=to_string(k1%10);
                c1=k1/10;

            }
            if(c1)s2+=to_string(c1);
           // cout<<s2<<endl;
            s1=s2;



        }
       // cout<<k<<endl;
        reverse(s1.begin(),s1.end());
int st=0;
        while(s1[st]=='0')st++;
        s1=s1.substr(st,s1.length()-st);
   return s1;
}
