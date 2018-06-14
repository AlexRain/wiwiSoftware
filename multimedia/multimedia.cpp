#include "multimedia.h"


extern "C"
{
#include "libavformat/avformat.h"
}

multimedia::multimedia()
{

}

multimedia::~multimedia()
{

}

QString multimedia::getVersion()
{
	av_register_all();
	unsigned version = avcodec_version();
	avcodec_configuration();
	return QString::number(version);
}
