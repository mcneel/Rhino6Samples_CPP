#include "stdafx.h"
#include "SampleLayerContextMenuExtension.h"

CSampleLayerContextMenuExtension::CSampleLayerContextMenuExtension(CRhinoPlugIn& thePlugIn)
  : CRhinoContextMenuExtension(thePlugIn, *(thePlugIn.PlugInModuleState()), true)
{
  m_iAddItemID0 = m_iAddItemID1 = m_iAddItemID2 = -1;
}

CSampleLayerContextMenuExtension::~CSampleLayerContextMenuExtension()
{
}

bool CSampleLayerContextMenuExtension::ShouldExtendContextMenu(CRhinoContextMenuContext& context)
{
  // Extend the layer list's context menu
  if (0 == ON_UuidCompare(context.m_uuid, CRhinoContextMenuExtension::UUIDLayerList()))
    return true;
  return false;
}

void CSampleLayerContextMenuExtension::ExtendContextMenu(CRhinoContextMenuContext& context, CRhinoContextMenu& context_menu)
{
  UNREFERENCED_PARAMETER(context_menu);

  m_iAddItemID0 = m_iAddItemID1 = m_iAddItemID2 = -1;
  if (0 == ON_UuidCompare(context.m_uuid, CRhinoContextMenuExtension::UUIDLayerList()))
  {
    m_iAddItemID0 = context_menu.AddItem(L"Sample Context Menu Item 1");
    m_iAddItemID1 = context_menu.AddItem(L"Sample Context Menu Item 2");
    m_iAddItemID2 = context_menu.AddItem(L"Sample Context Menu Item 3");
  }
}

void CSampleLayerContextMenuExtension::OnCommand(CRhinoContextMenuContext& context, int iAddItemID, UINT nID, CRhinoContextMenu& context_menu)
{
  UNREFERENCED_PARAMETER(context);
  UNREFERENCED_PARAMETER(nID);
  UNREFERENCED_PARAMETER(context_menu);

  if (iAddItemID == m_iAddItemID0)
    RhinoApp().Print(L"Sample Context Menu Item 1 selected.\n");
  else if (iAddItemID == m_iAddItemID1)
    RhinoApp().Print(L"Sample Context Menu Item 2 selected.\n");
  else if (iAddItemID == m_iAddItemID2)
    RhinoApp().Print(L"Sample Context Menu Item 3 selected.\n");
}

void CSampleLayerContextMenuExtension::OnInitPopupMenu(CRhinoContextMenuContext& context, HWND hWnd, HMENU hMenuOriginal, HMENU hMenuRuntime, CRhinoContextMenu& context_menu)
{
  UNREFERENCED_PARAMETER(context);
  UNREFERENCED_PARAMETER(hWnd);
  UNREFERENCED_PARAMETER(hMenuOriginal);
  UNREFERENCED_PARAMETER(hMenuRuntime);
  UNREFERENCED_PARAMETER(context_menu);

  // TODO...
}
