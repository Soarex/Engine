struct VSOutput {
	float4 position	 : SV_POSITION;
	float4 color	 : COLOR;
	float2 uv		 : TEXCOORD;
	int slot		 : SLOT;
};

SamplerState samAnisotropic { 
	Filter = ANISOTROPIC;
	MaxAnisotropy = 4;
	AddressU = WRAP;
	AddressV = WRAP; 
};

Texture2D textureBase[32];

float4 main(VSOutput input) : SV_Target {
	float4 color;
	switch (input.slot) {
	case  0: color = textureBase[ 0].Sample(samAnisotropic, input.uv); break;
	case  1: color = textureBase[ 1].Sample(samAnisotropic, input.uv); break;
	case  2: color = textureBase[ 2].Sample(samAnisotropic, input.uv); break;
	case  3: color = textureBase[ 3].Sample(samAnisotropic, input.uv); break;
	case  4: color = textureBase[ 4].Sample(samAnisotropic, input.uv); break;
	case  5: color = textureBase[ 5].Sample(samAnisotropic, input.uv); break;
	case  6: color = textureBase[ 6].Sample(samAnisotropic, input.uv); break;
	case  7: color = textureBase[ 7].Sample(samAnisotropic, input.uv); break;
	case  8: color = textureBase[ 8].Sample(samAnisotropic, input.uv); break;
	case  9: color = textureBase[ 9].Sample(samAnisotropic, input.uv); break;
	case 10: color = textureBase[10].Sample(samAnisotropic, input.uv); break;
	case 11: color = textureBase[11].Sample(samAnisotropic, input.uv); break;
	case 12: color = textureBase[12].Sample(samAnisotropic, input.uv); break;
	case 13: color = textureBase[13].Sample(samAnisotropic, input.uv); break;
	case 14: color = textureBase[14].Sample(samAnisotropic, input.uv); break;
	case 15: color = textureBase[15].Sample(samAnisotropic, input.uv); break;
	case 16: color = textureBase[16].Sample(samAnisotropic, input.uv); break;
	case 17: color = textureBase[17].Sample(samAnisotropic, input.uv); break;
	case 18: color = textureBase[18].Sample(samAnisotropic, input.uv); break;
	case 19: color = textureBase[19].Sample(samAnisotropic, input.uv); break;
	case 20: color = textureBase[20].Sample(samAnisotropic, input.uv); break;
	case 21: color = textureBase[21].Sample(samAnisotropic, input.uv); break;
	case 22: color = textureBase[22].Sample(samAnisotropic, input.uv); break;
	case 23: color = textureBase[23].Sample(samAnisotropic, input.uv); break;
	case 24: color = textureBase[24].Sample(samAnisotropic, input.uv); break;
	case 25: color = textureBase[25].Sample(samAnisotropic, input.uv); break;
	case 26: color = textureBase[26].Sample(samAnisotropic, input.uv); break;
	case 27: color = textureBase[27].Sample(samAnisotropic, input.uv); break;
	case 28: color = textureBase[28].Sample(samAnisotropic, input.uv); break;
	case 29: color = textureBase[29].Sample(samAnisotropic, input.uv); break;
	case 30: color = textureBase[30].Sample(samAnisotropic, input.uv); break;
	case 31: color = textureBase[31].Sample(samAnisotropic, input.uv); break;
	default: color = input.color; break;
	}					

	return color;				  
		
}								  
