import sys

xml_template = """<mxfile host="app.diagrams.net">
  <diagram name="UC15-SairPerfil" id="uc15_seq">
    <mxGraphModel dx="1000" dy="600" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="750" pageHeight="350" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        
        <mxCell id="actor" parent="1" style="shape=umlActor;verticalLabelPosition=bottom;verticalAlign=top;html=1;outlineConnect=0;" value="ADMIN / CAIXA" vertex="1">
          <mxGeometry height="60" width="30" x="40" y="20" as="geometry" />
        </mxCell>
        <mxCell id="life_actor" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="260" width="2" relative="1" as="geometry">
            <mxPoint x="55" y="90" as="sourcePoint" />
            <mxPoint x="55" y="350" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="v_header" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;" value=":View" vertex="1">
          <mxGeometry height="28" width="80" x="220" y="60" as="geometry" />
        </mxCell>
        <mxCell id="life_v" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="260" width="2" relative="1" as="geometry">
            <mxPoint x="260" y="90" as="sourcePoint" />
            <mxPoint x="260" y="350" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="ctrl_header" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;" value=":Controller" vertex="1">
          <mxGeometry height="28" width="100" x="460" y="60" as="geometry" />
        </mxCell>
        <mxCell id="life_ctrl" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="260" width="2" relative="1" as="geometry">
            <mxPoint x="510" y="90" as="sourcePoint" />
            <mxPoint x="510" y="350" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Controller -> View: menuAdmin / menuCaixa -->
        <mxCell id="msg_cv0" parent="1" style="endArrow=open;html=1;fontSize=10;endSize=10;" value="menuAdmin() / menuCaixa()" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="510" y="120" as="sourcePoint" />
            <mxPoint x="260" y="120" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Actor -> View: seleciona 0 -->
        <mxCell id="msg_cv1" parent="1" style="endArrow=open;html=1;fontSize=10;endSize=10;" value="seleciona 0 (sair)" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="55" y="160" as="sourcePoint" />
            <mxPoint x="260" y="160" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- View -> Controller: return 0 -->
        <mxCell id="msg_cv2" parent="1" style="endArrow=open;html=1;fontSize=10;dashed=1;endSize=10;" value="return 0" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="260" y="200" as="sourcePoint" />
            <mxPoint x="510" y="200" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="note" parent="1" style="shape=note;whiteSpace=wrap;html=1;backgroundOutline=1;darkOpacity=0.05;fillColor=#FFF2CC;strokeColor=#D6B656;fontSize=9;" value="break while(true)&#xa;limpar sessao" vertex="1">
          <mxGeometry height="40" width="100" x="530" y="210" as="geometry" />
        </mxCell>

        <!-- Controller -> View: menuPrincipal() again -->
        <mxCell id="msg_cv3" parent="1" style="endArrow=open;html=1;fontSize=10;endSize=10;" value="menuPrincipal()" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="510" y="270" as="sourcePoint" />
            <mxPoint x="260" y="270" as="targetPoint" />
          </mxGeometry>
        </mxCell>

      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
"""
with open("uc15.drawio", "w") as f:
    f.write(xml_template)
