struct VSInput {
	float4 position : POSITION;
	float4 color	: COLOR;
	float2 uv		: TEXCOORD;
	int  slot		: SLOT;
};

struct VSOutput {
	float4 position	 : SV_POSITION;
	float4 color	 : COLOR;
	float2 uv		 : TEXCOORD;
	int slot		 : SLOT;
};

VSOutput main(VSInput input) {
	VSOutput output;
	output.position = input.position;
	output.color = input.color;
	output.uv = input.uv;
	output.slot = input.slot;
	return output;
}