#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca {
	struct Settings {
		unsigned short m_maxSummaryWidth;
		bool m_tableView;
	};
	extern Settings g_settings;
}

#endif