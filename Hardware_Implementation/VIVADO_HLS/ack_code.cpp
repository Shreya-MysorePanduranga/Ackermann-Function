#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <ap_int.h>
#include <iostream>
#include <vector>
#include <hls_math.h>

using namespace std;

typedef ap_axis <32,2,5,6> int_side_ch;

unsigned int x,y;

int ack(int,int);

void ack(hls:: stream<int_side_ch> &inStream  , hls:: stream<int_side_ch> &outStream)
{
	#pragma HLS INTERFACE axis port=inStream
	#pragma HLS INTERFACE axis port=outStream
	#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
	int_side_ch val_in;
	int_side_ch val_out;
	int m,n;
	val_in= inStream.read();
	m=(unsigned int)val_in.data;
	val_in= inStream.read();
	n=(unsigned int)val_in.data;
    cout<<"M is = "<<m<<endl;
    cout<<"N is = "<<n<<endl;

	int value[30000];
	size_t size = 0;
	for ( ; ; )
	{
	    if (m == 0)
		{
	        n++;
	        if (size-- == 0)
			{
	            break;
	        }
	        m = value[size];
	        continue;
	    }
	    if (n == 0)
		{
	        m--;
	        n = 1;
	        continue;
	    }
	    size_t index = size++;
	    value[index] = m - 1;
	    n--;
	}
	cout<<"Hello World\n";
	cout << "Ackermann of M and N is = " << n << endl;

	val_out.data= n;
	outStream.write(val_out);
}
