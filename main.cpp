#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{
    IrrlichtDevice *device = createDevice(EDT_OPENGL, dimension2d<u32>(512,512), 32, false, false, false, 0);
    device->setWindowCaption(L"Irrlicht Hello World Tutorial");

    IVideoDriver *driver = device->getVideoDriver();
    ISceneManager *smgr = device->getSceneManager();
    IGUIEnvironment *guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! You are now running Irrlicht Engine!", rect<int>(10,10,200,22), true);

    IAnimatedMesh *mesh = smgr->getMesh("beast.b3d");
    IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);

    if (node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
        ITexture *texture = driver->getTexture("beast1.png");
        node->setFrameLoop(1, 25);
        node->setMaterialTexture(0, texture);
        node->setRotation(vector3df(0, 180, 0));

    }

    ICameraSceneNode *camera = smgr->addCameraSceneNode(0, vector3df(-100, 100, 150), vector3df(0, 5, 20));

    while(device->run())
    {
        driver->beginScene(true, true, SColor(255, 100, 101, 140));
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}