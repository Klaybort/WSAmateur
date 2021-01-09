#pragma once

#include <QQuickAsyncImageProvider>
#include <QThreadPool>

class AsyncImageResponse : public QQuickImageResponse, public QRunnable
{
    QString mId;
    QSize mRequestedSize;
    QImage mImage;

    public:
        AsyncImageResponse(const QString &id, const QSize &requestedSize);

        QQuickTextureFactory *textureFactory() const override {
            return QQuickTextureFactory::textureFactoryForImage(mImage);
        }

        void run() override;

    private:
        bool loadFromDisk();
};

class AsyncImageProvider : public QQuickAsyncImageProvider
{
    QThreadPool mPool;

public:
    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override
    {
        AsyncImageResponse *response = new AsyncImageResponse(id, requestedSize);
        mPool.start(response);
        return response;
    }

};
