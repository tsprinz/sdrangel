///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef _AIRSPYHF_AIRSPYHFSETTINGS_H_
#define _AIRSPYHF_AIRSPYHFSETTINGS_H_

struct AirspyHFSettings {
	typedef enum {
		FC_POS_INFRA = 0,
		FC_POS_SUPRA,
		FC_POS_CENTER
	} fcPos_t;

	quint64 m_centerFrequency;
	quint32 m_devSampleRateIndex;
	qint32  m_LOppmTenths;
	quint32 m_log2Decim;
	fcPos_t m_fcPos;
    bool m_dcBlock;
    bool m_iqCorrection;
    bool m_transverterMode;
    qint64 m_transverterDeltaFrequency;
    quint32 m_bandIndex;

    AirspyHFSettings();
	void resetToDefaults();
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);
};

#endif /* _AIRSPYHF_AIRSPYHFSETTINGS_H_ */
