import sys

xml_template = """<mxfile host="app.diagrams.net">
  <diagram name="UC14-SelecionarPerfil" id="uc14_seq">
    <mxGraphModel dx="1000" dy="600" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="750" pageHeight="450" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        
        <mxCell id="actor" parent="1" style="shape=umlActor;verticalLabelPosition=bottom;verticalAlign=top;html=1;outlineConnect=0;" value="Utilizador" vertex="1">
          <mxGeometry height="60" width="30" x="30" y="20" as="geometry" />
        </mxCell>
        <mxCell id="life_actor" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="340" width="2" relative="1" as="geometry">
            <mxPoint x="45" y="90" as="sourcePoint" />
            <mxPoint x="45" y="430" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="v_header" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;" value=":View" vertex="1">
          <mxGeometry height="28" width="80" x="220" y="60" as="geometry" />
        </mxCell>
        <mxCell id="life_v" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="340" width="2" relative="1" as="geometry">
            <mxPoint x="260" y="90" as="sourcePoint" />
            <mxPoint x="260" y="430" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="ctrl_header" parent="1" style="rounded=0;whiteSpace=wrap;html=1;fontStyle=1;fontSize=11;" value=":Controller" vertex="1">
          <mxGeometry height="28" width="100" x="460" y="60" as="geometry" />
        </mxCell>
        <mxCell id="life_ctrl" parent="1" style="endArrow=none;html=1;dashed=1;strokeWidth=1;" edge="1">
          <mxGeometry height="340" width="2" relative="1" as="geometry">
            <mxPoint x="510" y="90" as="sourcePoint" />
            <mxPoint x="510" y="430" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Controller -> View -->
        <mxCell id="msg_cv1" parent="1" style="endArrow=open;html=1;fontSize=10;endSize=10;" value="menuPrincipal()" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="510" y="120" as="sourcePoint" />
            <mxPoint x="260" y="120" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Actor -> View -->
        <mxCell id="msg_actor1" parent="1" style="endArrow=open;html=1;fontSize=10;endSize=10;" value="escolhe perfil (0 = ADMIN / idCaixa)" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="45" y="160" as="sourcePoint" />
            <mxPoint x="260" y="160" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- View -> Controller -->
        <mxCell id="msg_vc1" parent="1" style="endArrow=open;html=1;fontSize=10;dashed=1;endSize=10;" value="return opcao" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="260" y="200" as="sourcePoint" />
            <mxPoint x="510" y="200" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="alt_box" parent="1" style="rounded=1;whiteSpace=wrap;html=1;fillColor=none;dashed=1;strokeWidth=1;fontSize=10;" value="alt" vertex="1">
          <mxGeometry height="160" width="540" x="15" y="240" as="geometry" />
        </mxCell>

        <mxCell id="alt1_label" parent="1" style="text;html=1;fontSize=10;align=left;" value="[ADMIN]" vertex="1">
          <mxGeometry height="18" width="50" x="25" y="243" as="geometry" />
        </mxCell>
        
        <!-- Controller -> self -->
        <mxCell id="self4a" parent="1" style="endArrow=open;html=1;fontSize=9;endSize=10;edgeStyle=orthogonalEdgeStyle;rounded=0;" value="runAdmin()" edge="1">
          <mxGeometry height="20" width="20" relative="1" as="geometry">
            <mxPoint x="510" y="260" as="sourcePoint" />
            <mxPoint x="510" y="280" as="targetPoint" />
            <Array as="points">
              <mxPoint x="550" y="260" />
              <mxPoint x="550" y="280" />
            </Array>
          </mxGeometry>
        </mxCell>
        
        <!-- Controller -> View -->
        <mxCell id="msg5a" parent="1" style="endArrow=open;html=1;fontSize=9;endSize=10;" value="menuAdmin()" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="510" y="310" as="sourcePoint" />
            <mxPoint x="260" y="310" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <mxCell id="alt2_label" parent="1" style="text;html=1;fontSize=10;align=left;" value="[CAIXA]" vertex="1">
          <mxGeometry height="18" width="50" x="25" y="333" as="geometry" />
        </mxCell>
        
        <mxCell id="self4b" parent="1" style="endArrow=open;html=1;fontSize=9;endSize=10;edgeStyle=orthogonalEdgeStyle;rounded=0;" value="runCaixa(idCaixa)" edge="1">
          <mxGeometry height="20" width="20" relative="1" as="geometry">
            <mxPoint x="510" y="350" as="sourcePoint" />
            <mxPoint x="510" y="370" as="targetPoint" />
            <Array as="points">
              <mxPoint x="550" y="350" />
              <mxPoint x="550" y="370" />
            </Array>
          </mxGeometry>
        </mxCell>
        
        <mxCell id="msg5b" parent="1" style="endArrow=open;html=1;fontSize=9;endSize=10;" value="menuCaixa()" edge="1">
          <mxGeometry height="2" relative="1" as="geometry">
            <mxPoint x="510" y="390" as="sourcePoint" />
            <mxPoint x="260" y="390" as="targetPoint" />
          </mxGeometry>
        </mxCell>

      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
"""
with open("uc14.drawio", "w") as f:
    f.write(xml_template)
