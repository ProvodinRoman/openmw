#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include <QMap>

#include <boost/filesystem/path.hpp>

class QTextStream;
class QStringList;
class QString;

namespace Files { typedef std::vector<boost::filesystem::path> PathContainer;
                  struct ConfigurationManager;}

class GameSettings
{
public:
    GameSettings(Files::ConfigurationManager &cfg);
    ~GameSettings();

    inline QString value(const QString &key, const QString &defaultValue = QString())
    {
        return mSettings.value(key).isEmpty() ? defaultValue : mSettings.value(key);
    }


    inline void setValue(const QString &key, const QString &value)
    {
        mSettings.insert(key, value);
    }

    inline QStringList getDataDirs() { return mDataDirs; }
    inline void addDataDir(const QString &dir) { if(!dir.isEmpty()) mDataDirs.append(dir); }
    inline QString getDataLocal() {return mDataLocal; }

    QStringList values(const QString &key, const QStringList &defaultValues = QStringList());
    bool readFile(QTextStream &stream);
    bool writeFile(QTextStream &stream);

private:
    Files::ConfigurationManager &mCfgMgr;

    void validatePaths();
    QMap<QString, QString> mSettings;

    QStringList mDataDirs;
    QString mDataLocal;
};

#endif // GAMESETTINGS_HPP
