#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <math.h>
#include <iostream>


using namespace std;

typedef ap_axis<32,2,5,6> int_side_ch;

void ack(hls:: stream<int_side_ch> &inStream , hls:: stream<int_side_ch> &outStream);

int main()
{
	hls:: stream<int_side_ch> inputStream;
	hls:: stream<int_side_ch> outputStream;
	int first_num=3;
	int count;

	for (int idx=0; idx<2; idx++)
	{
		int_side_ch val_in;
		val_in.data=first_num+count;
		val_in.keep=1;
		val_in.strb=1;
		val_in.last=0;
		val_in.user=1;
		val_in.id=0;
		val_in.dest=0;

		inputStream<<val_in;
		count=2;
	}

	ack(inputStream , outputStream);


	int_side_ch val_out;
	outputStream.read(val_out);

}
