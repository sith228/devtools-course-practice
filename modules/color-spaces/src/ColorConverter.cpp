// Copyright 2017 Baranov Evgeny

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "../include/ColorConverter.h"
#include "../include/hsb_hsv_space.h"
#include "../include/lab_space.h"
#include "../include/rgb_space.h"
#include "../include/xyz_space.h"

ColorConverter::ColorConverter() : message_("") {}

void ColorConverter::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a color converter application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <value1> <value2> " +
        "<value3> <inType> <outType>\n\n" +

        "Where valueX arguments are integer numbers, " +
        "and <inType>, <outType> is one of 'HSV', 'RGB', 'LAB', 'XYZ'.\n";
}

bool ColorConverter::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

uint16_t ParseInt(const char* arg) {
    uint16_t value = std::stoi(arg);
    return value;
}

unsigned int ParseType(const char* arg) {
    unsigned int type(-1);
    if (strcmp(arg, "HSV"))
        type = 1;
    else if (strcmp(arg, "RGB"))
        type = 2;
    else if (strcmp(arg, "LAB"))
        type = 3;
    else if (strcmp(arg, "XYZ"))
        type = 4;
    else
        throw std::string("Wrong type!");
    return type;
}

void init(HSBHSVSpace* _hsbhsv, RGBSpace* _rgb, LABSpace* _lab, XYZSpace* _xyz,
    const Arguments& _args) {
    switch (_args.inType) {
    case 1:
        _hsbhsv = new HSBHSVSpace(_args.value1, _args.value2, _args.value3);
        break;
    case 2:
        _rgb = new RGBSpace(_args.value1, _args.value2, _args.value3);
        break;
    case 3:
        _lab = new LABSpace(_args.value1, _args.value2, _args.value3);
        break;
    case 4:
        _xyz = new XYZSpace(_args.value1, _args.value2, _args.value3);
        break;
    default:
        break;
    }
}

std::string ColorConverter::operator()(int argc, const char** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        arg_.value1 = ParseInt(argv[1]);
        arg_.value2 = ParseInt(argv[2]);
        arg_.value3 = ParseInt(argv[3]);
        arg_.inType = ParseType(argv[4]);
        arg_.outType = ParseType(argv[5]);
    } catch (std::string& str) {
        return str;
    }

    HSBHSVSpace *hsbhsv;
    RGBSpace *rgb;
    LABSpace *lab;
    XYZSpace *xyz;
    init(hsbhsv, rgb, lab, xyz, arg_);
    std::ostringstream stream;
    switch (arg_.outType) {
    case 1:
        if (rgb) {
            hsbhsv = new HSBHSVSpace(*rgb);
            stream << "RGB";
        } else if (lab) {
            hsbhsv = new HSBHSVSpace(*new RGBSpace(*new XYZSpace(*lab)));
            stream << "LAB";
        } else if (xyz) {
            hsbhsv = new HSBHSVSpace(*new RGBSpace(*xyz));
            stream << "XYZ";
        }
        stream << " to HSBHSV: " << std::endl <<
            "hue: "<< hsbhsv->GetHue() << std::endl <<
            "saturation: "<< hsbhsv->GetSaturation() << std::endl <<
            "brightnes: " << hsbhsv->GetValueBrightnes() << std::endl;
        break;
    case 2:
        if (hsbhsv) {
            rgb = new RGBSpace(*hsbhsv);
            stream << "HSBHSV";
        } else if (lab) {
            rgb = new RGBSpace(*new XYZSpace(*lab));
            stream << "LAB";
        } else if (xyz) {
            rgb = new RGBSpace(*xyz);
            stream << "XYZ";
        }
        stream << " to RGB: " << std::endl <<
            "R: " << rgb->GetRed() << std::endl <<
            "G: " << rgb->GetGreen() << std::endl <<
            "B: " << rgb->GetBlue() << std::endl;
        break;
    case 3:
        if (hsbhsv) {
            lab = new LABSpace(*new XYZSpace(*new RGBSpace(*hsbhsv)));
            stream << "HSBHSV";
        } else if (rgb) {
            lab = new LABSpace(*new XYZSpace(*rgb));
            stream << "RGB";
        } else if (xyz) {
            lab = new LABSpace(*xyz);
            stream << "XYZ";
        }
        stream << " to LAB: " << std::endl <<
            "A: " << lab->GetA() << std::endl <<
            "B: " << lab->GetB() << std::endl <<
            "Lightness: " << lab->GetLightness() << std::endl;
        break;
    case 4:
        if (hsbhsv) {
            xyz = new XYZSpace(*new RGBSpace(*hsbhsv));
            stream << "HSBHSV";
        } else if (rgb) {
            xyz = new XYZSpace(*rgb);
            stream << "RGB";
        } else if (lab) {
            xyz = new XYZSpace(*lab);
            stream << "LAB";
        }
        stream << " to XYZ: " << std::endl <<
            "X: " << xyz->GetX() << std::endl <<
            "Y: " << xyz->GetY() << std::endl <<
            "Z: " << xyz->GetZ() << std::endl;
        break;
    default:
        break;
    }
    message_ = stream.str();
    if (hsbhsv)
        delete hsbhsv;
    if (rgb)
        delete rgb;
    if (lab)
        delete lab;
    if (xyz)
        delete xyz;
    return message_;
}
