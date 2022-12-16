#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Pixels.h"
using namespace std;

void Task1() {
	ifstream layer("input/layer1.tga", ios_base::binary);
	char idLengthL;
	char colorMapTypeL;
	char dataTypeCodeL;
	short colorMapOriginL;
	short colorMapLengthL;
	char colorMapDepthL;
	short xOriginL;
	short yOriginL;
	short widthL;
	short heightL;
	char bitsPerPixelL;
	char imageDescriptorL;

	layer.read(&idLengthL, sizeof(idLengthL));
	layer.read(&colorMapTypeL, sizeof(colorMapTypeL));
	layer.read(&dataTypeCodeL, sizeof(dataTypeCodeL));
	layer.read((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	layer.read((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	layer.read(&colorMapDepthL, sizeof(colorMapDepthL));
	layer.read((char*)&xOriginL, sizeof(xOriginL));
	layer.read((char*)&yOriginL, sizeof(yOriginL));
	layer.read((char*)&widthL, sizeof(widthL));
	layer.read((char*)&heightL, sizeof(heightL));
	layer.read(&bitsPerPixelL, sizeof(bitsPerPixelL));
	layer.read(&imageDescriptorL, sizeof(imageDescriptorL));


	unsigned int areaL = widthL * heightL;


	vector<Pixel*> listL;
	for (unsigned int i = 0; i < areaL; i++) {
		Pixel* current = new Pixel();
		layer.read((char*)&current->blue, sizeof(current->blue));
		layer.read((char*)&current->green, sizeof(current->green));
		layer.read((char*)&current->red, sizeof(current->red));
		listL.push_back(current);
	}

	ifstream pattern("input/pattern1.tga", ios_base::binary);
	char idLengthP;
	char colorMapTypeP;
	char dataTypeCodeP;
	short colorMapOriginP;
	short colorMapLengthP;
	char colorMapDepthP;
	short xOriginP;
	short yOriginP;
	short widthP;
	short heightP;
	char bitsPerPixelP;
	char imageDescriptorP;

	pattern.read(&idLengthP, sizeof(idLengthP));
	pattern.read(&colorMapTypeP, sizeof(colorMapTypeP));
	pattern.read(&dataTypeCodeP, sizeof(dataTypeCodeP));
	pattern.read((char*)&colorMapOriginP, sizeof(colorMapOriginP));
	pattern.read((char*)&colorMapLengthP, sizeof(colorMapLengthP));
	pattern.read(&colorMapDepthP, sizeof(colorMapDepthP));
	pattern.read((char*)&xOriginP, sizeof(xOriginP));
	pattern.read((char*)&yOriginP, sizeof(yOriginP));
	pattern.read((char*)&widthP, sizeof(widthP));
	pattern.read((char*)&heightP, sizeof(heightP));
	pattern.read(&bitsPerPixelP, sizeof(bitsPerPixelP));
	pattern.read(&imageDescriptorP, sizeof(imageDescriptorP));


	unsigned int areaP = widthP * heightP;


	vector<Pixel*> listP;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* current = new Pixel();
		pattern.read((char*)&current->blue, sizeof(current->blue));
		pattern.read((char*)&current->green, sizeof(current->green));
		pattern.read((char*)&current->red, sizeof(current->red));
		listP.push_back(current);
	}
	ofstream createG("output/part1.tga", ios_base::binary);
	createG.write(&idLengthL, sizeof(idLengthL));
	createG.write(&colorMapTypeL, sizeof(colorMapTypeL));
	createG.write(&dataTypeCodeL, sizeof(dataTypeCodeL));
	createG.write((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	createG.write((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	createG.write(&colorMapDepthL, sizeof(colorMapDepthL));
	createG.write((char*)&xOriginL, sizeof(xOriginL));
	createG.write((char*)&yOriginL, sizeof(yOriginL));
	createG.write((char*)&widthL, sizeof(widthL));
	createG.write((char*)&heightL, sizeof(heightL));
	createG.write(&bitsPerPixelL, sizeof(bitsPerPixelL));
	createG.write(&imageDescriptorL, sizeof(imageDescriptorL));

	for (unsigned int i = 0; i < areaL; i++) {
		float tempB1 = listL[i]->blue / 255.0f;
		float tempB2 = listP[i]->blue / 255.0f;
		float tempB12 = (tempB1 * tempB2) * 255.0f + 0.5f;
		const char temp1 = (const char)tempB12;
		createG.write(&temp1, sizeof(temp1));


		float tempG1 = listL[i]->green / 255.0f;
		float tempG2 = listP[i]->green / 255.0f;
		float tempG12 = (tempG1 * tempG2) * 255.0f + 0.5f;
		const char temp2 = (const char)tempG12;
		createG.write(&temp2, sizeof(temp2));



		float tempR1 = listL[i]->red / 255.0f;
		float tempR2 = listP[i]->red / 255.0f;
		float tempR12 = (tempR1 * tempR2) * 255.0f + 0.5f;
		const char temp3 = (const char)tempR12;
		createG.write(&temp3, sizeof(temp3));
	}


}
bool TestTask1() {
	ifstream example("output/part1.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part1.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task2() {
	ifstream layer("input/layer2.tga", ios_base::binary);
	char idLengthL;
	char colorMapTypeL;
	char dataTypeCodeL;
	short colorMapOriginL;
	short colorMapLengthL;
	char colorMapDepthL;
	short xOriginL;
	short yOriginL;
	short widthL;
	short heightL;
	char bitsPerPixelL;
	char imageDescriptorL;

	layer.read(&idLengthL, sizeof(idLengthL));
	layer.read(&colorMapTypeL, sizeof(colorMapTypeL));
	layer.read(&dataTypeCodeL, sizeof(dataTypeCodeL));
	layer.read((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	layer.read((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	layer.read(&colorMapDepthL, sizeof(colorMapDepthL));
	layer.read((char*)&xOriginL, sizeof(xOriginL));
	layer.read((char*)&yOriginL, sizeof(yOriginL));
	layer.read((char*)&widthL, sizeof(widthL));
	layer.read((char*)&heightL, sizeof(heightL));
	layer.read(&bitsPerPixelL, sizeof(bitsPerPixelL));
	layer.read(&imageDescriptorL, sizeof(imageDescriptorL));


	unsigned int areaL = widthL * heightL;


	vector<Pixel*> listL;
	for (unsigned int i = 0; i < areaL; i++) {
		Pixel* current = new Pixel();
		layer.read((char*)&current->blue, sizeof(current->blue));
		layer.read((char*)&current->green, sizeof(current->green));
		layer.read((char*)&current->red, sizeof(current->red));
		listL.push_back(current);
	}

	ifstream pattern("input/car.tga", ios_base::binary);
	char idLengthP;
	char colorMapTypeP;
	char dataTypeCodeP;
	short colorMapOriginP;
	short colorMapLengthP;
	char colorMapDepthP;
	short xOriginP;
	short yOriginP;
	short widthP;
	short heightP;
	char bitsPerPixelP;
	char imageDescriptorP;

	pattern.read(&idLengthP, sizeof(idLengthP));
	pattern.read(&colorMapTypeP, sizeof(colorMapTypeP));
	pattern.read(&dataTypeCodeP, sizeof(dataTypeCodeP));
	pattern.read((char*)&colorMapOriginP, sizeof(colorMapOriginP));
	pattern.read((char*)&colorMapLengthP, sizeof(colorMapLengthP));
	pattern.read(&colorMapDepthP, sizeof(colorMapDepthP));
	pattern.read((char*)&xOriginP, sizeof(xOriginP));
	pattern.read((char*)&yOriginP, sizeof(yOriginP));
	pattern.read((char*)&widthP, sizeof(widthP));
	pattern.read((char*)&heightP, sizeof(heightP));
	pattern.read(&bitsPerPixelP, sizeof(bitsPerPixelP));
	pattern.read(&imageDescriptorP, sizeof(imageDescriptorP));


	unsigned int areaP = widthP * heightP;


	vector<Pixel*> listP;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* current = new Pixel();
		pattern.read((char*)&current->blue, sizeof(current->blue));
		pattern.read((char*)&current->green, sizeof(current->green));
		pattern.read((char*)&current->red, sizeof(current->red));
		listP.push_back(current);
	}

	ofstream createG("output/part2.tga", ios_base::binary);
	createG.write(&idLengthL, sizeof(idLengthL));
	createG.write(&colorMapTypeL, sizeof(colorMapTypeL));
	createG.write(&dataTypeCodeL, sizeof(dataTypeCodeL));
	createG.write((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	createG.write((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	createG.write(&colorMapDepthL, sizeof(colorMapDepthL));
	createG.write((char*)&xOriginL, sizeof(xOriginL));
	createG.write((char*)&yOriginL, sizeof(yOriginL));
	createG.write((char*)&widthL, sizeof(widthL));
	createG.write((char*)&heightL, sizeof(heightL));
	createG.write(&bitsPerPixelL, sizeof(bitsPerPixelL));
	createG.write(&imageDescriptorL, sizeof(imageDescriptorL));

	for (unsigned int i = 0; i < areaL; i++) {
		int tempB1 = listP[i]->blue;
		int tempB2 = listL[i]->blue;
		int tempB12 = tempB1 - tempB2;
		if (tempB12 < 0) {
			tempB12 = 0;
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}

		int tempG1 = listP[i]->green;
		int tempG2 = listL[i]->green;
		int tempG12 = tempG1 - tempG2;
		if (tempG12 < 0) {
			tempG12 = 0;
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}

		int tempR1 = listP[i]->red;
		int tempR2 = listL[i]->red;
		int tempR12 = tempR1 - tempR2;
		if (tempR12 < 0) {
			tempR12 = 0;
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
	}
}

bool TestTask2() {
	ifstream example("output/part2.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part2.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task3() {
	ifstream layer("input/layer1.tga", ios_base::binary);
	char idLengthL;
	char colorMapTypeL;
	char dataTypeCodeL;
	short colorMapOriginL;
	short colorMapLengthL;
	char colorMapDepthL;
	short xOriginL;
	short yOriginL;
	short widthL;
	short heightL;
	char bitsPerPixelL;
	char imageDescriptorL;

	layer.read(&idLengthL, sizeof(idLengthL));
	layer.read(&colorMapTypeL, sizeof(colorMapTypeL));
	layer.read(&dataTypeCodeL, sizeof(dataTypeCodeL));
	layer.read((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	layer.read((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	layer.read(&colorMapDepthL, sizeof(colorMapDepthL));
	layer.read((char*)&xOriginL, sizeof(xOriginL));
	layer.read((char*)&yOriginL, sizeof(yOriginL));
	layer.read((char*)&widthL, sizeof(widthL));
	layer.read((char*)&heightL, sizeof(heightL));
	layer.read(&bitsPerPixelL, sizeof(bitsPerPixelL));
	layer.read(&imageDescriptorL, sizeof(imageDescriptorL));


	unsigned int areaL = widthL * heightL;


	vector<Pixel*> listL;
	for (unsigned int i = 0; i < areaL; i++) {
		Pixel* current = new Pixel();
		layer.read((char*)&current->blue, sizeof(current->blue));
		layer.read((char*)&current->green, sizeof(current->green));
		layer.read((char*)&current->red, sizeof(current->red));
		listL.push_back(current);
	}

	ifstream pattern("input/pattern2.tga", ios_base::binary);
	char idLengthP;
	char colorMapTypeP;
	char dataTypeCodeP;
	short colorMapOriginP;
	short colorMapLengthP;
	char colorMapDepthP;
	short xOriginP;
	short yOriginP;
	short widthP;
	short heightP;
	char bitsPerPixelP;
	char imageDescriptorP;

	pattern.read(&idLengthP, sizeof(idLengthP));
	pattern.read(&colorMapTypeP, sizeof(colorMapTypeP));
	pattern.read(&dataTypeCodeP, sizeof(dataTypeCodeP));
	pattern.read((char*)&colorMapOriginP, sizeof(colorMapOriginP));
	pattern.read((char*)&colorMapLengthP, sizeof(colorMapLengthP));
	pattern.read(&colorMapDepthP, sizeof(colorMapDepthP));
	pattern.read((char*)&xOriginP, sizeof(xOriginP));
	pattern.read((char*)&yOriginP, sizeof(yOriginP));
	pattern.read((char*)&widthP, sizeof(widthP));
	pattern.read((char*)&heightP, sizeof(heightP));
	pattern.read(&bitsPerPixelP, sizeof(bitsPerPixelP));
	pattern.read(&imageDescriptorP, sizeof(imageDescriptorP));


	unsigned int areaP = widthP * heightP;


	vector<Pixel*> listP;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* current = new Pixel();
		pattern.read((char*)&current->blue, sizeof(current->blue));
		pattern.read((char*)&current->green, sizeof(current->green));
		pattern.read((char*)&current->red, sizeof(current->red));
		listP.push_back(current);
	}

	vector<Pixel*> listTemp;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* temp = new Pixel();
		float tempB1 = listL[i]->blue / 255.0f;
		float tempB2 = listP[i]->blue / 255.0f;
		float tempB12 = (tempB1 * tempB2) * 255.0f + 0.5f;
		const char temp1 = (const char)tempB12;
		temp->blue = temp1;

		float tempG1 = listL[i]->green / 255.0f;
		float tempG2 = listP[i]->green / 255.0f;
		float tempG12 = (tempG1 * tempG2) * 255.0f + 0.5f;
		const char temp2 = (const char)tempG12;
		temp->green = temp2;

		float tempR1 = listL[i]->red / 255.0f;
		float tempR2 = listP[i]->red / 255.0f;
		float tempR12 = (tempR1 * tempR2) * 255.0f + 0.5f;
		const char temp3 = (const char)tempR12;
		temp->red = temp3;

		listTemp.push_back(temp);
	}

	ifstream text("input/text.tga", ios_base::binary);
	char idLengthT;
	char colorMapTypeT;
	char dataTypeCodeT;
	short colorMapOriginT;
	short colorMapLengthT;
	char colorMapDepthT;
	short xOriginT;
	short yOriginT;
	short widthT;
	short heightT;
	char bitsPerPixelT;
	char imageDescriptorT;

	text.read(&idLengthT, sizeof(idLengthT));
	text.read(&colorMapTypeT, sizeof(colorMapTypeT));
	text.read(&dataTypeCodeT, sizeof(dataTypeCodeT));
	text.read((char*)&colorMapOriginT, sizeof(colorMapOriginT));
	text.read((char*)&colorMapLengthT, sizeof(colorMapLengthT));
	text.read(&colorMapDepthT, sizeof(colorMapDepthT));
	text.read((char*)&xOriginT, sizeof(xOriginT));
	text.read((char*)&yOriginT, sizeof(yOriginT));
	text.read((char*)&widthT, sizeof(widthT));
	text.read((char*)&heightT, sizeof(heightT));
	text.read(&bitsPerPixelT, sizeof(bitsPerPixelT));
	text.read(&imageDescriptorT, sizeof(imageDescriptorT));


	unsigned int areaT = widthT * heightT;


	vector<Pixel*> listT;
	for (unsigned int i = 0; i < areaT; i++) {
		Pixel* current = new Pixel();
		text.read((char*)&current->blue, sizeof(current->blue));
		text.read((char*)&current->green, sizeof(current->green));
		text.read((char*)&current->red, sizeof(current->red));
		listT.push_back(current);
	}

	ofstream createG("output/part3.tga", ios_base::binary);
	createG.write(&idLengthL, sizeof(idLengthL));
	createG.write(&colorMapTypeL, sizeof(colorMapTypeL));
	createG.write(&dataTypeCodeL, sizeof(dataTypeCodeL));
	createG.write((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	createG.write((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	createG.write(&colorMapDepthL, sizeof(colorMapDepthL));
	createG.write((char*)&xOriginL, sizeof(xOriginL));
	createG.write((char*)&yOriginL, sizeof(yOriginL));
	createG.write((char*)&widthL, sizeof(widthL));
	createG.write((char*)&heightL, sizeof(heightL));
	createG.write(&bitsPerPixelL, sizeof(bitsPerPixelL));
	createG.write(&imageDescriptorL, sizeof(imageDescriptorL));

	for (unsigned int i = 0; i < areaT; i++) {
		float tempB1 = listTemp[i]->blue / 255.0f;
		float tempB2 = listT[i]->blue / 255.0f;
		float tempB12 = 255.5f - ((1 - tempB1) * (1 - tempB2)) * 255;
		const char temp1 = (const char)tempB12;
		createG.write(&temp1, sizeof(temp1));

		float tempG1 = listTemp[i]->green / 255.0f;
		float tempG2 = listT[i]->green / 255.0f;
		float tempG12 = 255.5f - ((1 - tempG1) * (1 - tempG2)) * 255;
		const char temp2 = (const char)tempG12;
		createG.write(&temp2, sizeof(temp2));

		float tempR1 = listTemp[i]->red / 255.0f;
		float tempR2 = listT[i]->red / 255.0f;
		float tempR12 = 255.5f - ((1 - tempR1) * (1 - tempR2)) * 255;
		const char temp3 = (const char)tempR12;
		createG.write(&temp3, sizeof(temp3));
	}
}

bool TestTask3() {
	ifstream example("output/part3.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part3.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task4() {
	ifstream layer("input/layer2.tga", ios_base::binary);
	char idLengthL;
	char colorMapTypeL;
	char dataTypeCodeL;
	short colorMapOriginL;
	short colorMapLengthL;
	char colorMapDepthL;
	short xOriginL;
	short yOriginL;
	short widthL;
	short heightL;
	char bitsPerPixelL;
	char imageDescriptorL;

	layer.read(&idLengthL, sizeof(idLengthL));
	layer.read(&colorMapTypeL, sizeof(colorMapTypeL));
	layer.read(&dataTypeCodeL, sizeof(dataTypeCodeL));
	layer.read((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	layer.read((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	layer.read(&colorMapDepthL, sizeof(colorMapDepthL));
	layer.read((char*)&xOriginL, sizeof(xOriginL));
	layer.read((char*)&yOriginL, sizeof(yOriginL));
	layer.read((char*)&widthL, sizeof(widthL));
	layer.read((char*)&heightL, sizeof(heightL));
	layer.read(&bitsPerPixelL, sizeof(bitsPerPixelL));
	layer.read(&imageDescriptorL, sizeof(imageDescriptorL));


	unsigned int areaL = widthL * heightL;


	vector<Pixel*> listL;
	for (unsigned int i = 0; i < areaL; i++) {
		Pixel* current = new Pixel();
		layer.read((char*)&current->blue, sizeof(current->blue));
		layer.read((char*)&current->green, sizeof(current->green));
		layer.read((char*)&current->red, sizeof(current->red));
		listL.push_back(current);
	}

	ifstream circles("input/circles.tga", ios_base::binary);
	char idLengthC;
	char colorMapTypeC;
	char dataTypeCodeC;
	short colorMapOriginC;
	short colorMapLengthC;
	char colorMapDepthC;
	short xOriginC;
	short yOriginC;
	short widthC;
	short heightC;
	char bitsPerPixelC;
	char imageDescriptorC;

	circles.read(&idLengthC, sizeof(idLengthC));
	circles.read(&colorMapTypeC, sizeof(colorMapTypeC));
	circles.read(&dataTypeCodeC, sizeof(dataTypeCodeC));
	circles.read((char*)&colorMapOriginC, sizeof(colorMapOriginC));
	circles.read((char*)&colorMapLengthC, sizeof(colorMapLengthC));
	circles.read(&colorMapDepthC, sizeof(colorMapDepthC));
	circles.read((char*)&xOriginC, sizeof(xOriginC));
	circles.read((char*)&yOriginC, sizeof(yOriginC));
	circles.read((char*)&widthC, sizeof(widthC));
	circles.read((char*)&heightC, sizeof(heightC));
	circles.read(&bitsPerPixelC, sizeof(bitsPerPixelC));
	circles.read(&imageDescriptorC, sizeof(imageDescriptorC));


	unsigned int areaC = widthC * heightC;


	vector<Pixel*> listC;
	for (unsigned int i = 0; i < areaC; i++) {
		Pixel* current = new Pixel();
		circles.read((char*)&current->blue, sizeof(current->blue));
		circles.read((char*)&current->green, sizeof(current->green));
		circles.read((char*)&current->red, sizeof(current->red));
		listC.push_back(current);
	}

	vector<Pixel*> listTemp;
	for (unsigned int i = 0; i < areaC; i++) {
		Pixel* temp = new Pixel();
		float tempB1 = listL[i]->blue / 255.0f;
		float tempB2 = listC[i]->blue / 255.0f;
		float tempB12 = (tempB1 * tempB2) * 255.0f + 0.5f;
		const char temp1 = (const char)tempB12;
		temp->blue = temp1;

		float tempG1 = listL[i]->green / 255.0f;
		float tempG2 = listC[i]->green / 255.0f;
		float tempG12 = (tempG1 * tempG2) * 255.0f + 0.5f;
		const char temp2 = (const char)tempG12;
		temp->green = temp2;

		float tempR1 = listL[i]->red / 255.0f;
		float tempR2 = listC[i]->red / 255.0f;
		float tempR12 = (tempR1 * tempR2) * 255.0f + 0.5f;
		const char temp3 = (const char)tempR12;
		temp->red = temp3;

		listTemp.push_back(temp);
	}

	ifstream pattern("input/pattern2.tga", ios_base::binary);
	char idLengthP;
	char colorMapTypeP;
	char dataTypeCodeP;
	short colorMapOriginP;
	short colorMapLengthP;
	char colorMapDepthP;
	short xOriginP;
	short yOriginP;
	short widthP;
	short heightP;
	char bitsPerPixelP;
	char imageDescriptorP;

	pattern.read(&idLengthP, sizeof(idLengthP));
	pattern.read(&colorMapTypeP, sizeof(colorMapTypeP));
	pattern.read(&dataTypeCodeP, sizeof(dataTypeCodeP));
	pattern.read((char*)&colorMapOriginP, sizeof(colorMapOriginP));
	pattern.read((char*)&colorMapLengthP, sizeof(colorMapLengthP));
	pattern.read(&colorMapDepthP, sizeof(colorMapDepthP));
	pattern.read((char*)&xOriginP, sizeof(xOriginP));
	pattern.read((char*)&yOriginP, sizeof(yOriginP));
	pattern.read((char*)&widthP, sizeof(widthP));
	pattern.read((char*)&heightP, sizeof(heightP));
	pattern.read(&bitsPerPixelP, sizeof(bitsPerPixelP));
	pattern.read(&imageDescriptorP, sizeof(imageDescriptorP));


	unsigned int areaP = widthP * heightP;


	vector<Pixel*> listP;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* current = new Pixel();
		pattern.read((char*)&current->blue, sizeof(current->blue));
		pattern.read((char*)&current->green, sizeof(current->green));
		pattern.read((char*)&current->red, sizeof(current->red));
		listP.push_back(current);
	}

	ofstream createG("output/part4.tga", ios_base::binary);
	createG.write(&idLengthL, sizeof(idLengthL));
	createG.write(&colorMapTypeL, sizeof(colorMapTypeL));
	createG.write(&dataTypeCodeL, sizeof(dataTypeCodeL));
	createG.write((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	createG.write((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	createG.write(&colorMapDepthL, sizeof(colorMapDepthL));
	createG.write((char*)&xOriginL, sizeof(xOriginL));
	createG.write((char*)&yOriginL, sizeof(yOriginL));
	createG.write((char*)&widthL, sizeof(widthL));
	createG.write((char*)&heightL, sizeof(heightL));
	createG.write(&bitsPerPixelL, sizeof(bitsPerPixelL));
	createG.write(&imageDescriptorL, sizeof(imageDescriptorL));

	for (unsigned int i = 0; i < areaL; i++) {
		int tempB1 = listTemp[i]->blue;
		int tempB2 = listP[i]->blue;
		int tempB12 = tempB1 - tempB2;
		if (tempB12 < 0) {
			tempB12 = 0;
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}

		int tempG1 = listTemp[i]->green;
		int tempG2 = listP[i]->green;
		int tempG12 = tempG1 - tempG2;
		if (tempG12 < 0) {
			tempG12 = 0;
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}

		int tempR1 = listTemp[i]->red;
		int tempR2 = listP[i]->red;
		int tempR12 = tempR1 - tempR2;
		if (tempR12 < 0) {
			tempR12 = 0;
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
	}

}

bool TestTask4() {
	ifstream example("output/part4.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part4.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}


void Task5() {
	ifstream layer("input/layer1.tga", ios_base::binary);
	char idLengthL;
	char colorMapTypeL;
	char dataTypeCodeL;
	short colorMapOriginL;
	short colorMapLengthL;
	char colorMapDepthL;
	short xOriginL;
	short yOriginL;
	short widthL;
	short heightL;
	char bitsPerPixelL;
	char imageDescriptorL;

	layer.read(&idLengthL, sizeof(idLengthL));
	layer.read(&colorMapTypeL, sizeof(colorMapTypeL));
	layer.read(&dataTypeCodeL, sizeof(dataTypeCodeL));
	layer.read((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	layer.read((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	layer.read(&colorMapDepthL, sizeof(colorMapDepthL));
	layer.read((char*)&xOriginL, sizeof(xOriginL));
	layer.read((char*)&yOriginL, sizeof(yOriginL));
	layer.read((char*)&widthL, sizeof(widthL));
	layer.read((char*)&heightL, sizeof(heightL));
	layer.read(&bitsPerPixelL, sizeof(bitsPerPixelL));
	layer.read(&imageDescriptorL, sizeof(imageDescriptorL));


	unsigned int areaL = widthL * heightL;


	vector<Pixel*> listL;
	for (unsigned int i = 0; i < areaL; i++) {
		Pixel* current = new Pixel();
		layer.read((char*)&current->blue, sizeof(current->blue));
		layer.read((char*)&current->green, sizeof(current->green));
		layer.read((char*)&current->red, sizeof(current->red));
		listL.push_back(current);
	}

	ifstream pattern("input/pattern1.tga", ios_base::binary);
	char idLengthP;
	char colorMapTypeP;
	char dataTypeCodeP;
	short colorMapOriginP;
	short colorMapLengthP;
	char colorMapDepthP;
	short xOriginP;
	short yOriginP;
	short widthP;
	short heightP;
	char bitsPerPixelP;
	char imageDescriptorP;

	pattern.read(&idLengthP, sizeof(idLengthP));
	pattern.read(&colorMapTypeP, sizeof(colorMapTypeP));
	pattern.read(&dataTypeCodeP, sizeof(dataTypeCodeP));
	pattern.read((char*)&colorMapOriginP, sizeof(colorMapOriginP));
	pattern.read((char*)&colorMapLengthP, sizeof(colorMapLengthP));
	pattern.read(&colorMapDepthP, sizeof(colorMapDepthP));
	pattern.read((char*)&xOriginP, sizeof(xOriginP));
	pattern.read((char*)&yOriginP, sizeof(yOriginP));
	pattern.read((char*)&widthP, sizeof(widthP));
	pattern.read((char*)&heightP, sizeof(heightP));
	pattern.read(&bitsPerPixelP, sizeof(bitsPerPixelP));
	pattern.read(&imageDescriptorP, sizeof(imageDescriptorP));


	unsigned int areaP = widthP * heightP;


	vector<Pixel*> listP;
	for (unsigned int i = 0; i < areaP; i++) {
		Pixel* current = new Pixel();
		pattern.read((char*)&current->blue, sizeof(current->blue));
		pattern.read((char*)&current->green, sizeof(current->green));
		pattern.read((char*)&current->red, sizeof(current->red));
		listP.push_back(current);
	}


	ofstream createG("output/part5.tga", ios_base::binary);
	createG.write(&idLengthP, sizeof(idLengthP));
	createG.write(&colorMapTypeL, sizeof(colorMapTypeL));
	createG.write(&dataTypeCodeP, sizeof(dataTypeCodeP));
	createG.write((char*)&colorMapOriginL, sizeof(colorMapOriginL));
	createG.write((char*)&colorMapLengthL, sizeof(colorMapLengthL));
	createG.write(&colorMapDepthL, sizeof(colorMapDepthL));
	createG.write((char*)&xOriginL, sizeof(xOriginL));
	createG.write((char*)&yOriginL, sizeof(yOriginL));
	createG.write((char*)&widthP, sizeof(widthP));
	createG.write((char*)&heightP, sizeof(heightP));
	createG.write(&bitsPerPixelP, sizeof(bitsPerPixelP));
	createG.write(&imageDescriptorP, sizeof(imageDescriptorP));


	for (unsigned int i = 0; i < areaL; i++) {
		float tempB1 = listP[i]->blue / 255.0f;
		if (tempB1 <= 0.5) {
			float tempB2 = listL[i]->blue / 255.0f;
			float tempB12 = 2 * (tempB1 * tempB2) * 255.0f + 0.5f;
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			float tempB2 = listL[i]->blue / 255.0f;
			float tempB12 = 255.5f - ((1 - tempB1) * (1 - tempB2)) * 255 * 2;
			const char temp = (const char)tempB12;
			createG.write(&temp, sizeof(temp));
		}

		float tempG1 = listP[i]->green / 255.0f;
		if (tempG1 <= 0.5) {
			float tempG2 = listL[i]->green / 255.0f;
			float tempG12 = 2 * (tempB1 * tempG2) * 255.0f + 0.5f;
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			float tempG2 = listL[i]->green / 255.0f;
			float tempG12 = 255.5f - ((1 - tempG1) * (1 - tempG2)) * 255 * 2;
			const char temp = (const char)tempG12;
			createG.write(&temp, sizeof(temp));
		}

		float tempR1 = listP[i]->red / 255.0f;
		if (tempR1 <= 0.5) {
			float tempR2 = listL[i]->red / 255.0f;
			float tempR12 = 2 * (tempR1 * tempR2) * 255.0f + 0.5f;
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
		else {
			float tempR2 = listL[i]->red / 255.0f;
			float tempR12 = 255.5f - ((1 - tempR1) * (1 - tempR2)) * 255 * 2;
			const char temp = (const char)tempR12;
			createG.write(&temp, sizeof(temp));
		}
	}
}

bool TestTask5() {
	ifstream example("output/part6.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part6.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task6() {
	ifstream example("input/car.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ofstream createG("output/part6.tga", ios_base::binary);
	createG.write(&idLength, sizeof(idLength));
	createG.write(&colorMapType, sizeof(colorMapType));
	createG.write(&dataTypeCode, sizeof(dataTypeCode));
	createG.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	createG.write((char*)&colorMapLength, sizeof(colorMapLength));
	createG.write(&colorMapDepth, sizeof(colorMapDepth));
	createG.write((char*)&xOrigin, sizeof(xOrigin));
	createG.write((char*)&yOrigin, sizeof(yOrigin));
	createG.write((char*)&width, sizeof(width));
	createG.write((char*)&height, sizeof(height));
	createG.write(&bitsPerPixel, sizeof(bitsPerPixel));
	createG.write(&imageDescriptor, sizeof(imageDescriptor));

	for (unsigned int i = 0; i < area; i++) {
		createG.write((char*)&list[i]->blue, sizeof(list[i]->blue));
		int temp = list[i]->green;
		temp += 200;
		if (temp > 255) {
			temp = 255;
			const char anothertemp = (const char)temp;
			createG.write(&anothertemp, sizeof(anothertemp));
		}
		else {
			const char anothertemp = (const char)temp;
			createG.write(&anothertemp, sizeof(anothertemp));
		}
		createG.write((char*)&list[i]->red, sizeof(list[i]->red));
	}
}


bool TestTask6() {
	ifstream example("output/part6.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part6.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task7() {
	ifstream example("input/car.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ofstream createG("output/part7.tga", ios_base::binary);
	createG.write(&idLength, sizeof(idLength));
	createG.write(&colorMapType, sizeof(colorMapType));
	createG.write(&dataTypeCode, sizeof(dataTypeCode));
	createG.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	createG.write((char*)&colorMapLength, sizeof(colorMapLength));
	createG.write(&colorMapDepth, sizeof(colorMapDepth));
	createG.write((char*)&xOrigin, sizeof(xOrigin));
	createG.write((char*)&yOrigin, sizeof(yOrigin));
	createG.write((char*)&width, sizeof(width));
	createG.write((char*)&height, sizeof(height));
	createG.write(&bitsPerPixel, sizeof(bitsPerPixel));
	createG.write(&imageDescriptor, sizeof(imageDescriptor));

	for (unsigned int i = 0; i < area; i++) {
		const char blue = 0;
		createG.write(&blue, sizeof(blue));
		createG.write((char*)&list[i]->green, sizeof(list[i]->green));
		int temp = list[i]->red;
		temp *= 4;
		if (temp > 255) {
			temp = 255;
			const char anothertemp = (const char)temp;
			createG.write(&anothertemp, sizeof(anothertemp));
		}
		else {
			const char anothertemp = (const char)temp;
			createG.write(&anothertemp, sizeof(anothertemp));
		}

	}
}

bool TestTask7() {
	ifstream example("output/part7.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part7.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}


void Task8() {
	ifstream example("input/car.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ofstream createR("output/part8_r.tga", ios_base::binary);
	createR.write(&idLength, sizeof(idLength));
	createR.write(&colorMapType, sizeof(colorMapType));
	createR.write(&dataTypeCode, sizeof(dataTypeCode));
	createR.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	createR.write((char*)&colorMapLength, sizeof(colorMapLength));
	createR.write(&colorMapDepth, sizeof(colorMapDepth));
	createR.write((char*)&xOrigin, sizeof(xOrigin));
	createR.write((char*)&yOrigin, sizeof(yOrigin));
	createR.write((char*)&width, sizeof(width));
	createR.write((char*)&height, sizeof(height));
	createR.write(&bitsPerPixel, sizeof(bitsPerPixel));
	createR.write(&imageDescriptor, sizeof(imageDescriptor));

	for (unsigned int i = 0; i < area; i++) {
		createR.write((char*)&list[i]->red, sizeof(list[i]->red));
		createR.write((char*)&list[i]->red, sizeof(list[i]->red));
		createR.write((char*)&list[i]->red, sizeof(list[i]->red));
	}

	ofstream createG("output/part8_g.tga", ios_base::binary);
	createG.write(&idLength, sizeof(idLength));
	createG.write(&colorMapType, sizeof(colorMapType));
	createG.write(&dataTypeCode, sizeof(dataTypeCode));
	createG.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	createG.write((char*)&colorMapLength, sizeof(colorMapLength));
	createG.write(&colorMapDepth, sizeof(colorMapDepth));
	createG.write((char*)&xOrigin, sizeof(xOrigin));
	createG.write((char*)&yOrigin, sizeof(yOrigin));
	createG.write((char*)&width, sizeof(width));
	createG.write((char*)&height, sizeof(height));
	createG.write(&bitsPerPixel, sizeof(bitsPerPixel));
	createG.write(&imageDescriptor, sizeof(imageDescriptor));

	for (unsigned int i = 0; i < area; i++) {
		createG.write((char*)&list[i]->green, sizeof(list[i]->green));
		createG.write((char*)&list[i]->green, sizeof(list[i]->green));
		createG.write((char*)&list[i]->green, sizeof(list[i]->green));
	}

	ofstream createB("output/part8_b.tga", ios_base::binary);
	createB.write(&idLength, sizeof(idLength));
	createB.write(&colorMapType, sizeof(colorMapType));
	createB.write(&dataTypeCode, sizeof(dataTypeCode));
	createB.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	createB.write((char*)&colorMapLength, sizeof(colorMapLength));
	createB.write(&colorMapDepth, sizeof(colorMapDepth));
	createB.write((char*)&xOrigin, sizeof(xOrigin));
	createB.write((char*)&yOrigin, sizeof(yOrigin));
	createB.write((char*)&width, sizeof(width));
	createB.write((char*)&height, sizeof(height));
	createB.write(&bitsPerPixel, sizeof(bitsPerPixel));
	createB.write(&imageDescriptor, sizeof(imageDescriptor));

	for (unsigned int i = 0; i < area; i++) {
		createB.write((char*)&list[i]->blue, sizeof(list[i]->blue));
		createB.write((char*)&list[i]->blue, sizeof(list[i]->blue));
		createB.write((char*)&list[i]->blue, sizeof(list[i]->blue));
	}

}

bool TestTask8Blue() {
	ifstream example("output/part8_b.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part8_b.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

bool TestTask8Green() {
	ifstream example("output/part8_g.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part8_g.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}
bool TestTask8Red() {
	ifstream example("output/part8_r.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part8_r.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}
	return task;
}

void Task9() {
	ifstream exampleB("input/layer_blue.tga", ios_base::binary);
	char idLengthB;
	char colorMapTypeB;
	char dataTypeCodeB;
	short colorMapOriginB;
	short colorMapLengthB;
	char colorMapDepthB;
	short xOriginB;
	short yOriginB;
	short widthB;
	short heightB;
	char bitsPerPixelB;
	char imageDescriptorB;

	exampleB.read(&idLengthB, sizeof(idLengthB));
	exampleB.read(&colorMapTypeB, sizeof(colorMapTypeB));
	exampleB.read(&dataTypeCodeB, sizeof(dataTypeCodeB));
	exampleB.read((char*)&colorMapOriginB, sizeof(colorMapOriginB));
	exampleB.read((char*)&colorMapLengthB, sizeof(colorMapLengthB));
	exampleB.read(&colorMapDepthB, sizeof(colorMapDepthB));
	exampleB.read((char*)&xOriginB, sizeof(xOriginB));
	exampleB.read((char*)&yOriginB, sizeof(yOriginB));
	exampleB.read((char*)&widthB, sizeof(widthB));
	exampleB.read((char*)&heightB, sizeof(heightB));
	exampleB.read(&bitsPerPixelB, sizeof(bitsPerPixelB));
	exampleB.read(&imageDescriptorB, sizeof(imageDescriptorB));


	unsigned int areaB = widthB * heightB;


	vector<Pixel*> listB;
	for (unsigned int i = 0; i < areaB; i++) {
		Pixel* current = new Pixel();
		exampleB.read((char*)&current->blue, sizeof(current->blue));
		exampleB.read((char*)&current->green, sizeof(current->green));
		exampleB.read((char*)&current->red, sizeof(current->red));
		listB.push_back(current);
	}

	ifstream exampleG("input/layer_green.tga", ios_base::binary);
	char idLengthG;
	char colorMapTypeG;
	char dataTypeCodeG;
	short colorMapOriginG;
	short colorMapLengthG;
	char colorMapDepthG;
	short xOriginG;
	short yOriginG;
	short widthG;
	short heightG;
	char bitsPerPixelG;
	char imageDescriptorG;

	exampleG.read(&idLengthG, sizeof(idLengthG));
	exampleG.read(&colorMapTypeG, sizeof(colorMapTypeG));
	exampleG.read(&dataTypeCodeG, sizeof(dataTypeCodeG));
	exampleG.read((char*)&colorMapOriginG, sizeof(colorMapOriginG));
	exampleG.read((char*)&colorMapLengthG, sizeof(colorMapLengthG));
	exampleG.read(&colorMapDepthG, sizeof(colorMapDepthG));
	exampleG.read((char*)&xOriginG, sizeof(xOriginG));
	exampleG.read((char*)&yOriginG, sizeof(yOriginG));
	exampleG.read((char*)&widthG, sizeof(widthG));
	exampleG.read((char*)&heightG, sizeof(heightG));
	exampleG.read(&bitsPerPixelG, sizeof(bitsPerPixelG));
	exampleG.read(&imageDescriptorG, sizeof(imageDescriptorG));


	unsigned int areaG = widthG * heightG;


	vector<Pixel*> listG;
	for (unsigned int i = 0; i < areaG; i++) {
		Pixel* current = new Pixel();
		exampleG.read((char*)&current->blue, sizeof(current->blue));
		exampleG.read((char*)&current->green, sizeof(current->green));
		exampleG.read((char*)&current->red, sizeof(current->red));
		listG.push_back(current);
	}

	ifstream exampleR("input/layer_red.tga", ios_base::binary);
	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = widthR * heightR;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < areaR; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}


	ofstream create("output/part9.tga", ios_base::binary);
	create.write(&idLengthR, sizeof(idLengthR));
	create.write(&colorMapTypeR, sizeof(colorMapTypeR));
	create.write(&dataTypeCodeR, sizeof(dataTypeCodeR));
	create.write((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	create.write((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	create.write(&colorMapDepthR, sizeof(colorMapDepthR));
	create.write((char*)&xOriginR, sizeof(xOriginR));
	create.write((char*)&yOriginR, sizeof(yOriginR));
	create.write((char*)&widthR, sizeof(widthR));
	create.write((char*)&heightR, sizeof(heightR));
	create.write(&bitsPerPixelR, sizeof(bitsPerPixelR));
	create.write(&imageDescriptorR, sizeof(imageDescriptorR));

	for (unsigned int i = 0; i < areaR; i++) {
		create.write((char*)&listB[i]->blue, sizeof(listB[i]->blue));
		create.write((char*)&listG[i]->green, sizeof(listG[i]->green));
		create.write((char*)&listR[i]->red, sizeof(listR[i]->red));
	}
}
bool TestTask9() {
	ifstream example("output/part9.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part9.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}

	return task;
}

void Task10() {
	ifstream example("input/text2.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ofstream create("output/part10.tga", ios_base::binary);
	create.write(&idLength, sizeof(idLength));
	create.write(&colorMapType, sizeof(colorMapType));
	create.write(&dataTypeCode, sizeof(dataTypeCode));
	create.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	create.write((char*)&colorMapLength, sizeof(colorMapLength));
	create.write(&colorMapDepth, sizeof(colorMapDepth));
	create.write((char*)&xOrigin, sizeof(xOrigin));
	create.write((char*)&yOrigin, sizeof(yOrigin));
	create.write((char*)&width, sizeof(width));
	create.write((char*)&height, sizeof(height));
	create.write(&bitsPerPixel, sizeof(bitsPerPixel));
	create.write(&imageDescriptor, sizeof(imageDescriptor));

	for (int i = area - 1; i >= 0; i--) {
		Pixel* current = list[i];
		create.write((char*)&current->blue, sizeof(current->blue));
		create.write((char*)&current->green, sizeof(current->green));
		create.write((char*)&current->red, sizeof(current->red));
	}
}

bool TestTask10() {
	ifstream example("output/part10.tga", ios_base::binary);

	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;

	example.read(&idLength, sizeof(idLength));
	example.read(&colorMapType, sizeof(colorMapType));
	example.read(&dataTypeCode, sizeof(dataTypeCode));
	example.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
	example.read((char*)&colorMapLength, sizeof(colorMapLength));
	example.read(&colorMapDepth, sizeof(colorMapDepth));
	example.read((char*)&xOrigin, sizeof(xOrigin));
	example.read((char*)&yOrigin, sizeof(yOrigin));
	example.read((char*)&width, sizeof(width));
	example.read((char*)&height, sizeof(height));
	example.read(&bitsPerPixel, sizeof(bitsPerPixel));
	example.read(&imageDescriptor, sizeof(imageDescriptor));


	unsigned int area = width * height;


	vector<Pixel*> list;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		example.read((char*)&current->blue, sizeof(current->blue));
		example.read((char*)&current->green, sizeof(current->green));
		example.read((char*)&current->red, sizeof(current->red));
		list.push_back(current);
	}

	ifstream exampleR("examples/EXAMPLE_part10.tga", ios_base::binary);

	char idLengthR;
	char colorMapTypeR;
	char dataTypeCodeR;
	short colorMapOriginR;
	short colorMapLengthR;
	char colorMapDepthR;
	short xOriginR;
	short yOriginR;
	short widthR;
	short heightR;
	char bitsPerPixelR;
	char imageDescriptorR;

	exampleR.read(&idLengthR, sizeof(idLengthR));
	exampleR.read(&colorMapTypeR, sizeof(colorMapTypeR));
	exampleR.read(&dataTypeCodeR, sizeof(dataTypeCodeR));
	exampleR.read((char*)&colorMapOriginR, sizeof(colorMapOriginR));
	exampleR.read((char*)&colorMapLengthR, sizeof(colorMapLengthR));
	exampleR.read(&colorMapDepthR, sizeof(colorMapDepthR));
	exampleR.read((char*)&xOriginR, sizeof(xOriginR));
	exampleR.read((char*)&yOriginR, sizeof(yOriginR));
	exampleR.read((char*)&widthR, sizeof(widthR));
	exampleR.read((char*)&heightR, sizeof(heightR));
	exampleR.read(&bitsPerPixelR, sizeof(bitsPerPixelR));
	exampleR.read(&imageDescriptorR, sizeof(imageDescriptorR));


	unsigned int areaR = width * height;


	vector<Pixel*> listR;
	for (unsigned int i = 0; i < area; i++) {
		Pixel* current = new Pixel();
		exampleR.read((char*)&current->blue, sizeof(current->blue));
		exampleR.read((char*)&current->green, sizeof(current->green));
		exampleR.read((char*)&current->red, sizeof(current->red));
		listR.push_back(current);
	}

	bool task = true;

	if (idLength != idLengthR) {
		cout << "Length fail" << endl;
		task = false;
	}
	if (colorMapType != colorMapTypeR) {
		cout << "color Map Type fail" << endl;
		task = false;
	}
	if (dataTypeCodeR != dataTypeCode) {
		cout << "data type code failed" << endl;

		task = false;
	}
	if (colorMapOriginR != colorMapOrigin) {
		cout << "color map origin failed" << endl;
		task = false;
	}
	if (colorMapLengthR != colorMapLength) {
		cout << "color map length failed" << endl;
		task = false;
	}
	if (colorMapDepth != colorMapDepthR) {
		cout << "color map depth failed" << endl;
		task = false;
	}
	if (xOrigin != xOriginR) {
		cout << "x Origin failed" << endl;
		task = false;
	}
	if (yOrigin != yOriginR) {
		cout << "y origin failed" << endl;
		task = false;
	}
	if (width != widthR) {
		cout << "width failed" << endl;
		task = false;
	}
	if (height != heightR) {
		cout << "height failed" << endl;
		task = false;
	}
	if (bitsPerPixel != bitsPerPixelR) {
		cout << "bits per pixel failed" << endl;
		task = false;
	}
	if (imageDescriptor != imageDescriptorR) {
		cout << "image descrpitor failed" << endl;
		task = false;
	}

	if (list.size() != listR.size()) {
		cout << "list size fail" << endl;
		task = false;
	}

	for (unsigned int i = 0; i < area; i++) {
		if (list[i]->blue != listR[i]->blue) {
			cout << "pixel " << i << " blue failed" << endl;
			task = false;
		}
		if (list[i]->green != listR[i]->green) {
			cout << "pixel " << i << " green failed" << endl;
			task = false;
		}
		if (list[i]->red != listR[i]->red) {
			cout << "pixel " << i << " red failed" << endl;
			task = false;
		}
	}

	return task;
}

int main() {

	Task1();
	bool test1 = TestTask1();
	if (test1 == true) {
		cout << "Task 1 works" << endl;
	}
	else {
		cout << "Task 1 failed" << endl;
	}
	Task2();
	bool test2 = TestTask2();
	if (test2 == true) {
		cout << "Task 2 works" << endl;
	}
	else {
		cout << "Task 2 failed" << endl;
	}
	Task3();
	bool test3 = TestTask3();
	if (test3) {
		cout << "Task 3 works" << endl;
	}
	else {
		cout << "Task 3 failed" << endl;
	}
	Task4();
	bool test4 = TestTask4();
	if (test4 == true) {
		cout << "Task 4 works" << endl;
	}
	else {
		cout << "Task 4 failed" << endl;
	}
	Task5();
	bool test5 = TestTask5();
	if (test5) {
		cout << "Task 5 works" << endl;
	}
	else {
		cout << "Task 5 failed" << endl;
	}

	Task6();
	bool test6 = TestTask6();
	if (test6 == true) {
		cout << "Task 6 works" << endl;
	}
	else {
		cout << "Task 6 failed" << endl;
	}
	Task7();
	bool test7 = TestTask7();
	if (test7 == true) {
		cout << "Task 7 works" << endl;
	}
	else {
		cout << "Task 7 failed" << endl;
	}
	Task8();
	bool test8b = TestTask8Blue();
	if (test8b == true) {
		cout << "Task 8 BLUE works" << endl;
	}
	else {
		cout << "Task 8 BLUE failed" << endl;
	}
	bool test8g = TestTask8Green();
	if (test8g == true) {
		cout << "Task 8 GREEN works" << endl;
	}
	else {
		cout << "Task 8 GREEN failed" << endl;
	}
	bool test8r = TestTask8Red();
	if (test8r == true) {
		cout << "Task 8 RED works" << endl;
	}
	else {
		cout << "Task 8 RED failed" << endl;
	}
	Task9();
	bool test9 = TestTask9();
	if (test9 == true) {
		cout << "Task 9 works" << endl;
	}
	else {
		cout << "Task 9 failed" << endl;
	}
	Task10();
	bool test10 = TestTask10();
	if (test10 == true) {
		cout << "Task 10 Works" << endl;
	}
	else {
		cout << "Task 10 failed" << endl;
	}



}